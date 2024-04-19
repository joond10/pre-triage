# Ontario Pre-Triage Application for Healthcare Facilities

A C++ application designed by Seneca's School of Software Design & Data Science and coded by me. Its use case is for healthcare facilities that are required to screen patients and separate those in need of contagion testing from others. This process must be conducted in an orderly manner, informing patients of the expected wait time and notifying them when they can be admitted. It utilizes C++ at the level of Seneca Polytechnic's OOP244 course which covers dynamic memory allocation, encapsulation, abstraction, inheritance, and polymorphism.

## The Pre-Triage Application
The application starts by displaying a simple menu with three options:
```Text
Ontario Pre-Triage Application for Healthcare Facilities
1- Register
2- Admit
0- Exit
>
```
#### Register
The register option is selected to screen patients before getting into the healthcare facility. The user can select between a contagion Test or Triage.

Contagion test is selected if the patient is at the healthcare facility for a contagion Test. In this case, the patient's name and OHIP number is entered and then a ticket will be printed with a call number and estimated wait time for admission for the patient.

If Triage is selected then in addition to the patient's name and OHIP number, the symptoms of the patient are entered. Then a ticket for Triage is printed with an estimated wait time for admission.

#### Admit
Admit is selected when the contagion Test area or the Triage section is ready to accept a patient. After selecting contagion or Triage, the patient with the next ticket in line will be called. Based on the time of the call, the average wait time for the next patient for that line up (contagion or Triage) will be updated.

