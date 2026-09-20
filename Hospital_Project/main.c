#include <stdio.h>
#include <stdlib.h>
#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20
#define MAX_PATIENTS 500

extern int patientCount;

void welcomeMenu();
int getPatientData(int number);
void displayBedMap();
void displaySpecialties();
void displayWards();
void displayPatientBill(int number);
void displaySummaryReport();
void displayAllPatients();
void clearScreen();

int main()
{
    int choice;
    int patientNumber;

    do{
        welcomeMenu();
        //Getting user Input

        printf("Enter yout choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                clearScreen();
                if(patientCount < MAX_PATIENTS){
                    if(getPatientData(patientCount)){
                        patientCount++;
                        printf("Patient registerd!!\n");
                    }
                }
                else{
                    printf("Maximum patients reached.\n");
                }
                break;
            case 2:
                clearScreen();
                displayBedMap();
                break;
            case 3:
                clearScreen();
                displaySpecialties();
                break;
            case 4:
                clearScreen();
                displayWards();
                break;
            case 5:
                clearScreen();
                printf("Enter patient number: ");
                scanf("%d",&patientNumber);

                if (patientNumber >= 1 && patientNumber <= patientCount){
                    displayPatientBill(patientNumber-1);
                }else{
                    printf("Invalid patient ID\n");
                }
                break;
            case 6:
                clearScreen();
                displayAllPatients();
                break;
            case 7:
                clearScreen();
                displaySummaryReport();
                break;
            case 8:
                clearScreen();
                printf("Exitted from the system.Thank you\n");
                break;
            default:
                clearScreen();
                printf("Invalid choice. Try Again\n");
        }

    }while(choice !=8);
    return 0;
}

//Clearing terminal screen after each input
void clearScreen(){
    system("cls");
}
