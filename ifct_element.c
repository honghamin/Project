//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};

typedef struct ifs_ele
{
	int index; //number
	int age; //age
	int detected_time; //time
	place_t history_place[N_HISTORY]; //place[N_HISTORY]
} ifs_ele_t;  //구조체 선언 및 실체 만들기  

void* ifctele_genElement(int index, int age, unsigned int detected_time, 
	int history_place[N_HISTORY])
	{
		ifs_ele_t* ptr;
		
		ptr = (ifs_ele_t*)malloc(4*sizeof(int));
		ptr->index = index;
		ptr->age = age;
		ptr->detected_time = detected_time;
		ptr->history_place[N_HISTORY] = history_place[N_HISTORY];
		
		return ptr;
		
	}    //동적 메모리 할당 후 환자 정보를 받아서 구조체 만들기  
	
char* ifctele_getPlaceName(int placeIndex)
{
	return countryName[N_PLACE+1][MAX_PLACENAME];
}    //도시 번호를 이름으로 리턴해주는 함수  

int ifctele_getAge(void* obj)
{
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
	
	return ptr->age; //age 포인터 출력  
}

unsigned int ifctele_getinfestedTime(void* obj)
{ 
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
	
	return ptr->detected_time; //detected_time 포인터 출력  
}

int ifctele_getHistPlaceIndex(void* obj, int index)
{
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
	
	return ptr->history_place[N_HISTORY]; //history_place 배열 포인터 출력  
}

void ifcele_printElement(void* obj)
{
	ifs_ele_t*ptr = (ifs_ele_t*)obj;
	
	printf("Age : %i\n", ptr->age);
	printf("Time : %i\n", ptr->detected_time);
	printf("Place History : %i\n", ptr->history_place[N_HISTORY]);
}   //환자 정보를 출력하는 함수  

	
