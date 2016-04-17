/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

int length(char *);
int count_length(char *, char *, int, int);

char * find_common_route(char * hacklist, char *codelist, int *cost){
	if (hacklist == NULL || codelist == NULL){
		return NULL;
	}
	int len, i, j, k, res, count, c1, c2, *arr;
	len = length(hacklist);
	arr = (int *)malloc(len*sizeof(int));
	for (i = 0; i <= len; i++){
		arr[i] = 0;
	}
	for (i = 0; hacklist[i] != '\0'; i++){
		res = count = 0;
		for (j = 0; codelist[j] != '\0'; j++){
			if (hacklist[i] == codelist[j]){
				count = count_length(hacklist, codelist, i + 1, j + 1);
				if (res < count){
					res = count;
				}
			}
		}
		arr[i] = res;
	}
	res = 0;
	for (i = 1; i < len; i++){
		if (arr[res] < arr[i]){
			res = i;
		}
		else if (arr[res] == arr[i]){
			c1 = c2 = 0;
			for (k = res; k < arr[res]; k++){
				c1 += (hacklist[k] - 'A' + 1);
			}
			for (k = i; k < arr[i]; k++){
				c2 += (hacklist[k] - 'A' + 1);
			}
			if (c1>c2){
				res = i;
			}
			else if (c1 = c2){
				if (hacklist[res]>hacklist[i]){
					res = i;
				}
			}
		}
	}
	char *str = (char*)malloc(arr[res] * sizeof(char));
	k = 0;
	for (k = 0, i = res; k < arr[res]; i++){
		str[k] = hacklist[i];
		k++;
	}
	str[k] = '\0';
	c1 = 0;
	for (k = res, i = 0; i < arr[res]; i++, k++){
		c1 += (hacklist[k] - 'A' + 1);
	}
	*cost = c1;
	return str;
}

int length(char *str){
	int i;
	for (i = 0; str[i] != '\0'; i++){
		continue;
	}
	//
	return i;
}
int count_length(char *hack, char *code, int i, int j){
	int len = 1;
	for (; hack[i] != '\0'&&code[j] != '\0'; i++, j++){
		if (hack[i] == code[j]){
			len++;
		}
		else{
			break;
		}
	}
	return len;
}