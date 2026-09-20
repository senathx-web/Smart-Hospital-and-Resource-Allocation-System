# Smart Hospital Admission & Billing System

A menu-driven Hospital system written in C language to patient registration, medical specialty & emergency levels selection,hospital ward admission,bed allocation,patient billing and hospital summary reports.

## Features

### 1. Patient Registration

The system allows to register new patients and record their information.

- Register up to 500 patients
- Store patient name and age
- Select medical specialty
- Select emergency level
- Choose ward admission
- allocate available beds
- Validate user input
- Generate patient IDs

### 2. Waiting-Time Calculation

Estimated waiting time is calculated using:

**Waiting Time = Queue Count × Consultation Time**

### 3. Emergency Surcharge

| Em/Level | Description | Surcharge |
|---:|---|---:|
| 1 | Normal | 0% |
| 2 | Urgent | 20% |
| 3 | Critical | 50% |

### 4.Bed Allocation

The system automatically searches for a available bed in the selected ward and select it to the patient.If the ward is full, the admission is rejected.

### 5. Patient Billing

The system calculates:

- Base consultation fee
- Emergency surcharge
- Ward cost
- Gross total
- Age subsidy
- Final payable amount

### 6. Hospital Summary Report

The report provides:

- Total patients
- Urgency breakdown
- Total revenue
- Total discounts
- Ward occupancy

## Program Preview

### Main Menu

<img width="400" height="256" alt="menu" src="https://github.com/user-attachments/assets/2f95cfb8-4420-450d-bc6c-4d175d35be2d" />




### Patient Registration

<img width="382" height="337" alt="registration" src="https://github.com/user-attachments/assets/eef5eb67-23c4-40a7-8027-750316890222" />


### Bed Assignment

<img width="440" height="277" alt="bedoccupied" src="https://github.com/user-attachments/assets/57a8f0a1-b237-4767-941d-07e304b56462" />

### Bed Availability

<img width="1036" height="480" alt="bedavailability" src="https://github.com/user-attachments/assets/fe495814-9718-443a-bec2-16a09b4a8c2a" />


### Patient Bill

<img width="643" height="411" alt="bill" src="https://github.com/user-attachments/assets/6c923d8a-5126-4070-9e5b-8c6173c21d60" />


### All Patients

<img width="514" height="409" alt="plist" src="https://github.com/user-attachments/assets/e6265c9d-abb9-442e-ba4d-18226b9d2374" />


### Hospital Summary Report

<img width="499" height="458" alt="psummary" src="https://github.com/user-attachments/assets/79d37de1-0f17-4baa-8e52-de1cf70b27d3" />




## Project Structure

```text
Hospital_Project/
│
├── main.c
├── data.c
├── input.c
├── calculations.c
├── display.c
├__ Hospital_Project.cbp
```

## Main Program Files

### `main.c`

Contains the main program loop and menu system.

Responsibilities include:

- Displaying the main menu
- Receiving user menu selections
- Calling the appropriate functions
- Registering new patients
- Displaying patient bills
- Displaying hospital information
- Generating summary reports
- Handling program exit

### `data.c`

Contains the shared hospital and patient data used throughout the program.

This includes:

- Medical specialty information
- Specialty consultation fees
- Consultation times
- Daily patient capacities
- Hospital ward information
- Daily ward rates
- Ward capacities
- Bed occupancy information
- Patient information
- Queue counts
- Final billing amounts
- Discount amounts

### `input.c`

Contains functions responsible for patient registration and input validation.

Responsibilities include:

- Collecting patient information
- Validating emergency levels
- Selecting medical specialties
- Selecting ward admission
- Selecting hospital wards
- Automatically assigning available beds
- Checking ward availability
- Recording admission days
- Updating specialty queue counts

### `calculations.c`

Contains the calculation functions used by the system.

Functions include:

- Waiting time calculation
- Emergency surcharge calculation
- Ward cost calculation
- Gross bill calculation
- Age based discount calculation
- Final payable amount calculation

### `display.c`

Contains the functions responsible for displaying information to the user.

Responsibilities include:

- Main menu display
- Bed availability display
- Specialty information
- Ward information
- Patient bills
- All registered patients
- Hospital summary reports
- Revenue and discount information
- Ward occupancy statistics

---

## Hospital Configuration

### Medical Specialties

| ID | Specialty | Base Fee (LKR) | Consultation Time | Daily Capacity |
|---:|---|---:|---:|---:|
| 1 | General Practice (OPD) | 1,500 | 15 min | 30 |
| 2 | Paediatrics | 2,500 | 20 min | 20 |
| 3 | Cardiology | 4,500 | 30 min | 12 |
| 4 | Neurology | 5,000 | 30 min | 10 |

### Hospital Wards

| ID | Ward | Daily Bed Rate (LKR) | Capacity |
|---:|---|---:|---:|
| 1 | General Ward | 3,000 | 20 |
| 2 | Paediatric Ward | 6,000 | 10 |
| 3 | Surgical Ward | 12,000 | 10 |
| 4 | ICU (Intensive Care Unit) | 25,000 | 5 |

---

## Emergency / Triage Levels

| Level | Description | Emergency Surcharge |
|---:|---|---:|
| 1 | Normal | 0% |
| 2 | Urgent | 20% |
| 3 | Critical | 50% |




## How to Run

### Using Code::Blocks

1. Open **Code::Blocks**.
2. Open the project file:

```text
Smart-Hospital-Admission-Billing.cbp
```
3. Build the project.
4. Run the program.

## Project Purpose

The purpose of this project is to demonstrate the practical application of fundamental C programming concepts by developing a small scale hospital management system.

The system combines:

- Patient registration
- Medical specialty management
- Emergency level handling
- Queue and waiting time calculation
- Hospital ward management
- Automatic bed allocation
- Patient billing
- Age based discounts
- Bed occupancy monitoring
- Hospital performance reporting

## Authors

- **[Senath_x](https://github.com/senathx-web)**
