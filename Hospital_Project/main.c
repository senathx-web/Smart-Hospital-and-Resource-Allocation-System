#include <stdio.h>
#include <stdlib.h>

#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20
#define MAX_PATIENTS 500

void welcomeMenu();
extern int patientCount;

void getPatientData(int number);
void displayBedMap();
void displaySpecialties();
void displayWards();
void displayPatientBill(int number);
void displaySummaryReport();
void displayAllPatients();


int main()
{
    int choice;
    int patientNumber;

    do{
        welcomeMenu();
        printf("Enter yout choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                if(patientCount < MAX_PATIENTS){
                    getPatientData(patientCount);
                    patientCount++;
                    printf("Patient registerd!!\n");

                }
                else{
                    printf("Maximum patients reached.\n");
                }
                break;
            case 2:
                displayBedMap();
                break;
            case 3:
                displaySpecialties();
                break;
            case 4:
                displayWards();
                break;
            case 5:
                printf("Enter patient number: ");
                scanf("%d",&patientNumber);

                if (patientNumber >= 1 && patientNumber <= patientCount){
                    displayPatientBill(patientNumber-1);
                }else{
                    printf("Invalid patient ID\n");
                }
            case 6:
                displayAllPatients();
                break;
            case 7:
                displaySummaryReport();
                break;
            case 8:
                printf("Exitted from the system.Thank you\n");
                break;
            default:
                printf("Invalid choice. Try Again\n");

        }

    }while(choice !=8);


    return 0;

}
