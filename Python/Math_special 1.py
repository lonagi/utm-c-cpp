#!/usr/bin/env python
# coding: utf-8

# In[1]:


import sys
import random
import math


# In[2]:


import wolframclient as wl
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sympy import *
from sympy.plotting import plot
import networkx as nx


# In[3]:


#28 var
#F(x1) = {x2,x3}, F(x2) = {x5,x6}, F(x3) = {x2,x4,x6}, F(x4) = {x6}, F(x5) = {x8}, F(x6) = {x5,x7,x8}, F(x7) = {x8}, F(x8) = 0


# In[4]:


#Соединяем точки рёбрами быстро
G = nx.DiGraph()

nodes = [1, 2, 3, 4, 5, 6, 7, 8]
edges = [(1,2), (1,3), (2,5), (2,6), (3,2), (3,4), (3,6), (4,6), (5,8), (6,5), (6,7), (6,8), (7,8)]
G.add_nodes_from(nodes)
G.add_edges_from(edges)


# In[5]:


#Второе аналитическое представление

edges


# In[6]:


#Геометрическое представление

nx.draw_circular(G,
        node_color = "green",
        node_size = 2000, 
        with_labels = True,
        arrowsize = 30,
        font_color = "white",
        font_size = 20
        )


# In[7]:


#Матрица смежности
matrix_smej = nx.adjacency_matrix(G)
Matrix(matrix_smej.toarray())


# In[8]:


#Матрица инцидентности
matrix_inc = -nx.incidence_matrix(G, oriented=True)
mi = matrix_inc.toarray().transpose()
Matrix(mi)


# In[9]:


#Список смежности

a = {}

for i in G.nodes():
    a[i] = []
    for j in G.edges():
        if(j[0]==i):
            a[i].append(j[1])
            
df = pd.DataFrame(a.items())
print(df.to_string(index=False, header=False))


# In[10]:


#Степени

gxp = []
for i in G.nodes():
    gxp.append((i,len(G.out_edges(i))))
    
gxm = []
for i in G.nodes():
    gxm.append((i,len(G.in_edges(i))))

gx = nx.degree(G)
gxp = pd.merge(pd.DataFrame(gxp), pd.DataFrame(gxm), on=0)
gx = pd.merge(pd.DataFrame(gxp), pd.DataFrame(gx), on=0)
gx.columns = ["x","g+(x)","g-(x)","g(x)"]

print(gx.to_string(index=False))


# In[ ]:


#Классификация


# In[11]:


#Петли

for i in G.edges():
    if(i[0]==i[1]):
        print(i)
else:
    print("Нет петлей")


# In[31]:


#Вершины смежности

vertice = 5

a = {}

a = {vertice:[]}
for j in G.edges():
    if(j[0]==vertice):
        a[vertice].append(j[1])
    if(j[1]==vertice):
        a[vertice].append(j[0])
            
df = pd.DataFrame(a.items())
print(df.to_string(index=False, header=False))


# In[23]:


#Ребра инцидентности
edge = 1

df = pd.DataFrame(G.edges(edge))

print(df.to_string(index=False, header=False))


# In[75]:


#Подграфы