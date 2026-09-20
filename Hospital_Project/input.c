#include <stdio.h>
#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20
#define MAX_PATIENTS 500

extern char patientNames[MAX_PATIENTS][50];
extern int patientAges [MAX_PATIENTS];
extern int emergencyLevels[MAX_PATIENTS];
extern int patientSpecialties[MAX_PATIENTS];
extern char *specialtyNames[NUM_SPECIALTIES];
extern float specialtyFees[NUM_SPECIALTIES];
extern char *wardNames[NUM_WARDS];
extern float dailywardRates[NUM_WARDS];
extern int patientWards[MAX_PATIENTS];
extern int admittedToWard[MAX_PATIENTS];
extern int admittedDays[MAX_PATIENTS];
extern int assignedBeds[MAX_PATIENTS];
extern int wardCapacity[NUM_WARDS];
extern int bedOccupancy[NUM_WARDS][MAX_BEDS];

extern int queueCount[NUM_SPECIALTIES];


// Registering a new patient to the system

int getPatientData(int number){
    printf("--------------------------------\n");
    printf("         Registration\n");
    printf("--------------------------------\n");

    printf("Enter patient Name: ");
    scanf(" %[^\n]",patientNames[number]);

    printf("Enter patient age: ");
    scanf("%d",&patientAges[number]);

    printf("\nEmergency/Triage Level\n");
    printf("1.Normal\n");
    printf("2.Urgent\n");
    printf("3.Critical\n");


    do{
        printf("Enter Emergency level: ");
        scanf("%d",&emergencyLevels[number]);
    } while(emergencyLevels[number] <1 || emergencyLevels[number]>3);


    printf("-------- Specialties -------\n");

    for(int i =0; i< NUM_SPECIALTIES;i++){
        printf("%d  %s  %.2f \n",i+1,specialtyNames[i],specialtyFees[i]);
    }

    do{

        printf("Enter specialty: ");
        scanf("%d",&patientSpecialties[number]);
    } while(patientSpecialties[number]<1 ||patientSpecialties[number]> NUM_SPECIALTIES);


    printf("\nWard Admission\n");
    printf("1. Yes\n");
    printf("0. No\n");

    do
    {
        printf("Admitted to ward?");
        scanf("%d",&admittedToWard[number]);

        if (admittedToWard[number] != 0 && admittedToWard[number] != 1)
        {
            printf("Invalid input.Try again\n");
        }
    } while (admittedToWard[number] != 0 && admittedToWard[number] != 1);



    if (admittedToWard[number] == 1){
        printf("\nHospital Wards\n");
        for (int i = 0; i < NUM_WARDS; i++){
            printf("%d. %s   LKR %.2f/day\n", i + 1,wardNames[i],dailywardRates[i]);
        }

        do{
            printf("select ward: ");
            scanf("%d",&patientWards[number]);

            if (patientWards[number] < 1 || patientWards[number]>NUM_WARDS){
                printf("Invalid ward.Try again.\n");
            }
        } while (patientWards[number] < 1 || patientWards[number]>NUM_WARDS);

        int wardIndex =patientWards[number] - 1;
        int availableBed = -1;

        for (int bed = 0; bed < wardCapacity[wardIndex];bed++){
            if (bedOccupancy[wardIndex][bed] == 0){
                availableBed = bed;
                break;
            }
        }
        if (availableBed == -1){
            printf("Sorry, this ward is full.\n");
            patientWards[number] = 0;
            admittedToWard[number] = 0;
            admittedDays[number] = 0;
            assignedBeds[number] = -1;
            return 0;
        }
        assignedBeds[number] = availableBed;
        bedOccupancy[wardIndex][availableBed] = 1;

        printf("Bed assigned successfully: Bed #%02d\n",availableBed + 1);


        do{
            printf("Enter number of days admitted: ");
            scanf("%d", &admittedDays[number]);

            if (admittedDays[number] <= 0){
                printf("Number of days must be greater than 0.\n");
            }
        } while(admittedDays[number] <= 0);

    }
    else{
        patientWards[number] = 0;
        admittedDays[number] = 0;
        assignedBeds[number] = -1;
    }
    queueCount[patientSpecialties[number]-1]++;

    return 1;
}



