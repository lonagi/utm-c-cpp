#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRMAXLEN 128

struct Restaurant {
  char name[STRMAXLEN];
  char address[STRMAXLEN];
  char phone[STRMAXLEN];
  char cat[STRMAXLEN];
  char spec[STRMAXLEN];
  int cplaces;
};

void allocList(struct Restaurant **RestaurantList, int RestaurantCount);
void fillKeyboard(struct Restaurant *RestaurantList, int RestaurantCount);
void printList(struct Restaurant *RestaurantList, int RestaurantCount);
void writeStruct(struct Restaurant *RestaurantList, int RestaurantCount);
void readStruct(struct Restaurant *RestaurantList, int RestaurantCount);
void printSelections(void);

void addRestaurant(struct Restaurant *RestaurantList, int RestaurantIndex);
void editRestaurant(struct Restaurant *RestaurantList, int RestaurantIndex);
int deleteRestaurant(struct Restaurant **RestaurantList, int RestaurantCount, int RestaurantIndex);

void deallocateMemory(struct Restaurant **RestaurantList, int RestaurantCount);

struct Restaurant findRestaurant(struct Restaurant *RestaurantList, int RestaurantCount, char* title);

int Append(struct Restaurant **RestaurantList, int RestaurantCount);
int insertRestaurant(struct Restaurant **RestaurantList, int RestaurantCount, int RestaurantIndex);
int sortRestaurants(struct Restaurant *RestaurantList, int RestaurantCount);

void quit(void);

int main(void) {

	struct Restaurant *RestaurantsList = NULL;
	int RestaurantCount = 0;

	int insertionIndex = 0;
	int deletionIndex = 0;
	int indexToChange = 0;

	char RestaurantToFind[20];

	int Selection;

	while (1) {
    printSelections();

		printf("Your Selection? ");
		scanf("%d", &Selection);

		switch(Selection) {
			case 1:
				printf("Type count of restaurants: ");
				scanf("%d", &RestaurantCount);
				allocList(&RestaurantsList, RestaurantCount);
				break;
			case 2:
				fillKeyboard(RestaurantsList, RestaurantCount);
				break;
      case 3:
				printf("Type name of the restaurant to find: ");
				scanf("%s", &*RestaurantToFind);
				findRestaurant(RestaurantsList, RestaurantCount, RestaurantToFind);
				break;  
      case 4:
				sortRestaurants(RestaurantsList, RestaurantCount);
				break;
      case 5:
				printf("Type index of element to change: ");
				scanf("%d", &indexToChange);
				editRestaurant(RestaurantsList, indexToChange);
				break;
      case 6:
				RestaurantCount = Append(&RestaurantsList, RestaurantCount);
				break;
      case 7:
				printf("Type index of element to delete: ");
				scanf("%d", &deletionIndex);
				RestaurantCount = deleteRestaurant(&RestaurantsList, RestaurantCount, deletionIndex);
				break;
      case 8:
				printf("Type index to insert: ");
				scanf("%d", &insertionIndex);
				RestaurantCount = insertRestaurant(&RestaurantsList, RestaurantCount, insertionIndex);
				break;
      case 9:
				writeStruct(RestaurantsList, RestaurantCount);
				break;
      case 10:
				readStruct(RestaurantsList, RestaurantCount);
				break;
			case 11:
				printList(RestaurantsList, RestaurantCount);
				break;
			case 12:
				deallocateMemory(&RestaurantsList, RestaurantCount);
				break;
			case 13:
				quit();
				break;
			default:
				printf("Are you sure you entered the right command?\n");
        printSelections();
        break;
		}
	}
	
  return 0;
}

void allocList(struct Restaurant **RestaurantList, int RestaurantCount) {
    *RestaurantList = malloc(sizeof(struct Restaurant) * RestaurantCount);
    printf("Ready. Restaurants = %d\n", RestaurantCount);
}

void fillKeyboard(struct Restaurant *RestaurantList, int RestaurantCount) {
        
	int i = 0;

	while (RestaurantCount--) {
			addRestaurant(RestaurantList, i);
			i++;
	}

}

void addRestaurant(struct Restaurant *RestaurantList, int RestaurantIndex) {

	char name[STRMAXLEN], address[STRMAXLEN], phone[STRMAXLEN], cat[STRMAXLEN], spec[STRMAXLEN];
  int cplaces;

	printf("Write about the restaurant \n");
	
	printf("Type Name: ");
	scanf("%s", *&name);
	strcpy(RestaurantList[RestaurantIndex].name, name);

  printf("Type Address: ");
	scanf("%s", *&address);
	strcpy(RestaurantList[RestaurantIndex].address, address);

  printf("Type Phone: ");
	scanf("%s", *&phone);
	strcpy(RestaurantList[RestaurantIndex].phone, phone);

  printf("Type Category: ");
	scanf("%s", *&cat);
	strcpy(RestaurantList[RestaurantIndex].cat, cat);
  
  printf("Type Specialisation: ");
	scanf("%s", *&spec);
	strcpy(RestaurantList[RestaurantIndex].spec, spec);

	printf("Type amount of available places ");
	scanf("%d", &RestaurantList[RestaurantIndex].cplaces);
}

int Append(struct Restaurant **RestaurantList, int RestaurantCount) {
    
	*RestaurantList = realloc(*RestaurantList, (sizeof(RestaurantList) + 1) * sizeof(struct Restaurant));
	addRestaurant(*RestaurantList, RestaurantCount);

  return ++RestaurantCount;
}

void printList(struct Restaurant *RestaurantList, int RestaurantCount) {

	int i;

	for (i = 0; i < RestaurantCount; i++) {
			
		if (RestaurantList == NULL) {
			printf("No");
			return;
		}

		printf("\n\tRestaurant info");
		printf("\n--------------------\n");
		printf("Name is: %s \n", RestaurantList[i].name);
    printf("Address is: %s \n", RestaurantList[i].address);
    printf("Phone is: %s \n", RestaurantList[i].phone);
    printf("Category is: %s \n", RestaurantList[i].cat);
    printf("Specialisation is: %s \n", RestaurantList[i].spec);
    printf("Amount of places: %d \n", RestaurantList[i].cplaces);
		printf("--------------------\n");
	}

}

struct Restaurant findRestaurant(struct Restaurant *RestaurantList, int RestaurantCount, char* name) {

	int i;

	for (i = 0; i < RestaurantCount; i++) {
			if (strcmp(RestaurantList[i].name, name) == 0) {
					printf("We have found the restaurant \n");
					return RestaurantList[i];
			}
	}

	printf("The restaurant haven't found \n");
    return RestaurantList[i];
}

void writeStruct(struct Restaurant *RestaurantList, int RestaurantCount) {

	FILE* outfile;
	
  outfile = fopen("output.txt", "wb");

	if (outfile == NULL) {
			fprintf(stderr, "Error with a file \n");
			exit(1);
	}

	fwrite(RestaurantList, sizeof(struct Restaurant), RestaurantCount, outfile);
	fclose(outfile);
}

void readStruct(struct Restaurant *RestaurantList, int RestaurantCount) {

	FILE* inputfile;

	inputfile = fopen("output.txt", "rb");

	if (inputfile == NULL) {
			fprintf(stderr, "Error with a file \n");
			exit(1);
	}

	fread(RestaurantList, sizeof(struct Restaurant), RestaurantCount, inputfile);
	fclose(inputfile);
}

void editRestaurant(struct Restaurant *RestaurantList, int RestaurantIndex) {
  printf("Type number of restaurant to edit: %d \n", RestaurantIndex + 1);
  addRestaurant(RestaurantList, RestaurantIndex);
}

int deleteRestaurant(struct Restaurant **RestaurantList, int RestaurantCount, int RestaurantIndex) {
    
	if (RestaurantIndex >= RestaurantCount) {
			printf("Error deleting\n");
			return -1;
	}
	
	*RestaurantList = realloc(*RestaurantList, (sizeof(RestaurantList) - 1) * sizeof(struct Restaurant));
	
	int i;
	
	for (i = RestaurantIndex; i < RestaurantCount; i++) {
		strcpy((*RestaurantList)[i].name, (*RestaurantList)[i + 1].name);
		strcpy((*RestaurantList)[i].address, (*RestaurantList)[i + 1].address);
    strcpy((*RestaurantList)[i].phone, (*RestaurantList)[i + 1].phone);
    strcpy((*RestaurantList)[i].cat, (*RestaurantList)[i + 1].cat);
    strcpy((*RestaurantList)[i].spec, (*RestaurantList)[i + 1].spec);
		(*RestaurantList)[i].cplaces = (*RestaurantList)[i + 1].cplaces;
	}
	
	printf("The restaurant deleted \n");
  return --RestaurantCount;
}

int insertRestaurant(struct Restaurant **RestaurantList, int RestaurantCount, int RestaurantIndex) {

	if (RestaurantIndex >= (RestaurantCount + 1)) {
			printf("Error inserting\n");
			return -1;
	}
	
	*RestaurantList = realloc(*RestaurantList, (sizeof(RestaurantList) + 1) * sizeof(struct Restaurant));

	int i;

	for (i = RestaurantCount - 1; i >= RestaurantIndex; i--) {
		strcpy((*RestaurantList)[i + 1].name, (*RestaurantList)[i].name);
		strcpy((*RestaurantList)[i + 1].address, (*RestaurantList)[i].address);
    strcpy((*RestaurantList)[i + 1].phone, (*RestaurantList)[i].phone);
    strcpy((*RestaurantList)[i + 1].cat, (*RestaurantList)[i].cat);
    strcpy((*RestaurantList)[i + 1].spec, (*RestaurantList)[i].spec);
		(*RestaurantList)[i + 1].cplaces = (*RestaurantList)[i].cplaces;
	}

	addRestaurant(*RestaurantList, RestaurantIndex);

  return ++RestaurantCount;
}

int sortRestaurants(struct Restaurant *RestaurantList, int RestaurantCount) {

	if (RestaurantCount < 2) {
			return 0;
	}

	printf("\n\t  ...sorting...\n");
	
	struct Restaurant temp;

	int swapped;
	int i = 0;

	do {
		swapped = 0;
		for (i = 0; i < RestaurantCount - 1; i++) {
			if (strcmp(RestaurantList[i].name, RestaurantList[i + 1].name) > 0) {
				temp = RestaurantList[i];
				RestaurantList[i] = RestaurantList[i + 1];
				RestaurantList[i + 1] = temp;
				swapped = 1;
			}
		}
	} while (swapped);

  return 0;
}

void deallocateMemory(struct Restaurant **RestaurantList, int RestaurantCount) {
	free(*RestaurantList);
	*RestaurantList = NULL;
	printf("Deallocated \n");
}

void quit() {
    
	printf("Are you sure you want to quit? y/n\n");
	
	char Selection;
	
	do {
		scanf("%c", &Selection);
	} while (Selection != 'y' && Selection != 'n');
	
	if (Selection == 'y') {
		exit(0);
	}
	
  return;
}

void printSelections(void) {
	printf("1\tAllocate memory \n");
	printf("2\tFill Restaurants information from keyboard \n");
  printf("3\tFind a Restaurant \n");
  printf("4\tSort Restaurants by title \n");
  printf("5\tEdit a Restaurant \n");
  printf("6\tAdd a Restaurant to the end \n");
  printf("7\tDelete a Restaurant \n");
  printf("8\tInsert a Restaurant \n");
  printf("9\tWrite Restaurants to the file \n");
	printf("10\tRead Restaurants from the file \n");
	printf("11\tList all available Restaurants \n");
	printf("12\tDeallocate memory\n");
	printf("13\tExit\n");
}