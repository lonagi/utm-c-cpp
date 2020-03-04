#!/usr/bin/env python
# coding: utf-8

# In[1]:


#Матрица путей


# In[2]:


import sys
import random
import math


# In[3]:


import wolframclient as wl
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sympy import *
from sympy.plotting import plot
import networkx as nx
import pydot


# In[4]:


from IPython.display import Image


# In[5]:


#25 var
#F(x1) = {x3,x4}, F(x2) = {x5, x6}, F(x3) = {x2,x6}, F(x4) = {x6}, F(x5) = {x6,x8}, F(x6) = {x8}, F(x7) = {x8}, F(x8)=0


# In[6]:


#Соединяем точки рёбрами быстро

G = nx.DiGraph()

nodes = (1, 2, 3, 4, 5, 6, 7, 8)
edges = [(1,3),(1,4),(2,5),(2,6),(3,2),(3,6),(4,6),(5,6),(5,8),(6,8),(7,8)]
G.add_nodes_from(nodes)
G.add_edges_from(edges)


# In[8]:


#Геометрическое представление
#Matplotlib
def drawM(G, pos = False):
    if(not pos):
        nx.draw_circular(G,
        node_color = "green",
        node_size = 2000, 
        with_labels = True,
        arrowsize = 30,
        font_color = "white",
        font_size = 20
        )
    else:
        nx.draw_circular(G,
        node_color = "green",
        node_size = 2000, 
        with_labels = True,
        arrowsize = 30,
        font_color = "white",
        font_size = 20,
        pos=pos
        )

drawM(G)


# In[9]:


#Второе аналитическое представление

edges


# In[10]:


#Матрица смежности

matrix_smej = nx.adjacency_matrix(G)
Matrix(matrix_smej.toarray())


# In[ ]:


#Матрица путей вручную

listpaths = []
for i in nodes:
    for j in (nx.all_simple_paths(G, source=i, target=8)):
        listpaths.append(j)
listpath2 = [ [0 for i in range(len(nodes))] for j in range(len(nodes)) ]
for i in listpaths:
    for j in range(1,len(nodes)+1):
        if(j in i[1:]):
            listpath2[i[0]-1][j-1] = 1
Matrix(listpath2)


# In[11]:


#Матрица путей алгоритом Уоршелла

def warshall(M):
    n = M.shape[0]
    W = M
    for k in range(n):
        for i in range(n):
            for j in range(n):
                W[i, j] = W[i, j] or (W[i, k] and W[k, j])
    return W
                
Matrix(warshall(matrix_smej.toarray()))


# In[12]:


MatPh = nx.floyd_warshall_numpy(G)
MatPh[MatPh == np.inf] = 0
Matrix(MatPh.astype(int))


# In[13]:


#Гамильтонов путь

def get2col(edges):
    edges2 = []
    for i in edges:
        edges2.append(i[1])
    return edges2

def get1col(edges):
    edges2 = []
    for i in edges:
        edges2.append(i[0])
    return edges2

#Проверка есть ли вершины без входа
issetgpath = True
for i in nodes[1:]:
    if(i in get2col(edges)):
        issetgpath = False

#Проверка на прерывание
if(issetgpath):
    gpath = nx.algorithms.tournament.hamiltonian_path(G)
    print(gpath)
    for i in range(len(gpath)):
        if(i != len(gpath)-1):
            if( (gpath[i],gpath[i+1]) not in edges ):
                issetgpath = False
    
if(not issetgpath):
    print("Нет Гамильтонова пути")


# In[20]:


#Список путей длины 1,2,3

for k in range(len(nodes)):
    for i in range(1,len(nodes)):
        for j in nx.all_simple_paths(G, source=i, target=len(nodes)):
            if(len(j)==k+1):
                print("Длина "+str(k)+": "+str(j))


# In[15]:


#Частичный граф,который является древовидностью с корнем x1.

def checkCont(edges_p, root):
    res = []
    sett = set(get1col(edges_p))
    for j in sett:
        if(j not in get2col(edges_p) and j != root):
            res.append(i)
    return res

root = 1

edges_p = []
for i in edges:
    if(i[0] not in get2col(edges)):
        edges_p.append(i)
        
for i in checkCont(edges_p,root):
    try:
        edges_p.remove(i)
    except:
        pass
        
PG = nx.DiGraph()
PG.add_nodes_from(nodes)
PG.add_edges_from(edges_p)
drawM(PG)


# In[30]:


def findParents(D,v):
    for i in D.edges():
        if(i[1]==v):
            return i[0]
        
def findChildren(D,v):
    ch =[]
    for i in D.edges():
        if(i[0]==v):
            ch.append(i[1])
    return ch

def findBrothers(D,v):
    ch = []
    for i in D.edges():
        if(i[1]==v and i[0] in get1col(D.edges()) and i[1] != v):
            ch.append(i[0])
    return ch


# In[31]:


#Древовидность. Найти все листья: отца, сыновей и братьев, предков и потомков вершины х5.

vertice = 5

D = nx.DiGraph()

edges_d = []

for i in edges:
    if(i[0]==vertice or i[1]==vertice):
        edges_d.append(i)
        
nodesD = []
for i in edges_d:
    for j in i:
        nodesD.append(j)

D.add_nodes_from(set(nodesD))
D.add_edges_from(edges_d)

drawM(D)
print("Отец: "+str(findParents(D,vertice)))
print("Потомки: "+str(findChildren(D,vertice)))
print("Братья: "+str(findBrothers(D,vertice)))


# In[ ]:


#8. Представить геометрически данный граф, Гамильтонов путь и построить древовидность.


# In[ ]:




