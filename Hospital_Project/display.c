//Displaying menus/welcome massages/ outputs  goes here
#include <stdio.h>

#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20
#define MAX_PATIENTS 500

extern char *wardNames[NUM_WARDS];
extern int wardCapacity[NUM_WARDS];
extern int bedOccupancy[NUM_WARDS][MAX_BEDS];

extern char *specialtyNames[NUM_SPECIALTIES];
extern float specialtyFees[NUM_SPECIALTIES];
extern int consultationTimes[NUM_SPECIALTIES];
extern int dailyPatientCap[NUM_SPECIALTIES];

extern int wardCapacity[NUM_WARDS];
extern float dailywardRates[NUM_WARDS];




void welcomeMenu(){
    printf("-----------------------------------------\n");
    printf("\t\t WELCOME \t\t\n");
    printf("-----------------------------------------\n");

    printf("1.Register patient\n");
    printf("2.Display Bed Availability\n");
    printf("3.Display specialities Details\n");
    printf("4.Display wards Details\n");
    printf("5.Display patient Bill\n");
    printf("6.Display All patients\n");
    printf("7.Generate summary Report\n");
    printf("8.Exit\n");

    printf("-----------------------------------------\n");
}

void displayBedMap(){
    for (int i = 0; i < NUM_WARDS; i++){
        printf("\n                                 %s               \n\n", wardNames[i]);
        for (int j = 0; j< wardCapacity[i]; j++){
            if (bedOccupancy[i][j] == 0){
                printf("  [Bed %02d:Available]  ",
                       j+1);
            }
            else{
                printf("  [Bed %02d: Occupied]  ",
                       j+1);
            }
            if ((j+1)%5 == 0){
                printf("\n");
            }
        }
        printf("\n");
    }
}

void displaySpecialties(){

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Speciality ID    Speciality Name                Base Fee    Consultation Time    Daily Patient Cup\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    for(int i =0; i< NUM_SPECIALTIES;i++){
        printf("%-15d  %-25s      %.2f         %d mins  %10d\n",i+1,specialtyNames[i],specialtyFees[i], consultationTimes[i], dailyPatientCap[i]);
    }
}

void displayWards(){
    printf("-------------------------------------------------------------------\n");
    printf("Ward ID    Ward Name                   Bed Rate    Bed Capacity\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < NUM_WARDS; i++){
            printf("%-10d%-26s   %-10.2f   %d \n", i + 1,wardNames[i],dailywardRates[i],wardCapacity[i]);
        }
}


