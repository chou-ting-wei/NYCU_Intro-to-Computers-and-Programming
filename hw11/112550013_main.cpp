#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "112550013_struct.h"

#define For(z, x, y) for(int z = x; z <= y; z ++)

int login = 0;
char loginID[15];

char branch_list[][20] = { "Taipei Xinyi", "Taipei Fuxing", "Taipei Tienmu", "Taipei Taipei 101", "Taipei Nanxi", 
"Taipei A4", "Taipei A13", "Taipei Xinsheng", "Taipei Banqiao", "Hsinchu", "Taichung", "Kaohsiung"};

int main() {
	reg_list rl;
	rl.init();
	res_list rsl;
	rsl.init();

	printf("Welcome to the Din Tai Fung Reservation System!\n");
	while (1) {
		if (!login) {
			printf("\n1. Login\n2. Registration\n3. End\n\nEnter your choice (1~3): ");
			int T;
			scanf("%d", &T);
			if (T == 1) {
				printf("\nPlease enter your ID number: ");
				char ID[15];
				scanf("%s", &ID);
				if (rl.find(ID)) {
					printf("Enter your password: ");
					char pwd[30];
					scanf("%s", &pwd);
					if (rl.chkPwd(ID, pwd)) {
						printf("Login!\n");
						login = 1;
						strcpy(loginID, ID);
					}
					else {
						printf("Invalid password. Please try again.\n");
					}
				}
				else {
					printf("Invalid ID number. Please try again.\n");
				}
			}
			else if (T == 2) {
				printf("\nPlease enter your ID number: ");
				char ID[15];
				scanf("%s", &ID);
				if (chkIDValid(ID) && !rl.find(ID)) {
					printf("Enter your password: ");
					char pwd[30];
					scanf("%s", &pwd);
					printf("Enter your name: ");
					char name[20];
					scanf("%s", &name);
					reg_node *node = (reg_node*)malloc(sizeof(reg_node));
					node->init(ID, name, pwd);
					rl.add(node);
					printf("Registration successful!\n");
				}
				else {
					printf("Invalid ID number. Please try again.\n");
				}
			}
			else if (T == 3) {
				printf("\nThank you! Goodbye!\n\n");
				break;
			}
			else {
				printf("Invalid choice. Please try again.\n");
			}
		}
		else {
			printf("\n1. Make Reservation\n2. Reservation Enquiry/Canceling\n3. Log Out\n\nEnter your choice (1~3): ");
			int T;
			scanf("%d", &T);
			if (T == 1) {
				printf("\nPlease choose the branch (1-12):\n");
				For(i, 0, 11) {
					printf("%2d. %s\n", i + 1, branch_list[i]);
				}
				printf("\nEnter your choice (1~12): ");
				int coi1;
				scanf("%d", &coi1);

				if (coi1 < 1 || coi1 > 12) {
					printf("Invalid choice. Please try again.\n");
					continue;
				}

				time_t timeNow;
				struct tm* time_info;
				time(&timeNow);
				time_info = localtime(&timeNow);
				char timeStr[sizeof"YYYY/mm/dd:HH"];
				strftime(timeStr, sizeof(timeStr), "%Y/%m/%d:%H", time_info);
				printf("\nThe current date is %s\nAvailable days:\n", timeStr);

				int nowh = time_info->tm_hour;
				int opY[10], opm[10], opd[10];
				For(i, 1, 7){
					if (i == 1) {
						if(nowh == 23) timeNow += 86400;
					}
					else {
						timeNow += 86400;
					}
					
					time_info = localtime(&timeNow);
					strftime(timeStr, sizeof(timeStr), "%Y/%m/%d", time_info);
					printf("%d. %s\n", i, timeStr);
					opY[i] = time_info->tm_year + 1900;
					opm[i] = time_info->tm_mon + 1;
					opd[i] = time_info->tm_mday;
				}

				printf("\nEnter your choice (0 to end): ");
				int coi2;
				scanf("%d", &coi2);

				int hr;
				if (coi2 == 0) continue;
				else {
					if (coi2 == 1) {
						printf("\nEnter hour (%d~23):", nowh + 1);
						scanf("%d", &hr);
						if (hr < nowh + 1 || hr > 23) {
							printf("Invalid hour. Please try again.\n");
							continue;
						}
					}
					else if (coi2 < 0 || coi2 > 7) {
						printf("Invalid choice. Please try again.\n");
						continue;
					}
					else {
						printf("\nEnter hour (0~23):");
						scanf("%d", &hr);
						if (hr < 0 || hr > 23) {
							printf("Invalid hour. Please try again.\n");
							continue;
						}
					}
				}
				printf("\nEnter the number of customers (1~30, 0 to end):");
				int cos;
				scanf("%d", &cos);
				if (cos == 0) continue;
				else {
					if (cos < 0 || cos > 30) {
						printf("Invalid number of customers. Please try again.\n");
						continue;
					}
				}

				char tmpdate[20] = "\0";
				char tmpY[5], tmpm[5], tmpd[5];
				_itoa(opY[coi2], tmpY, 10);
				_itoa(opm[coi2], tmpm, 10);
				_itoa(opd[coi2], tmpd, 10);
				strcat(tmpdate, tmpY);
				strcat(tmpdate, "-");
				if (opm[coi2] / 10 == 0) strcat(tmpdate, "0");
				strcat(tmpdate, tmpm);
				strcat(tmpdate, "-");
				if (opd[coi2] / 10 == 0) strcat(tmpdate, "0");
				strcat(tmpdate, tmpd);
				res_node* node = (res_node*)malloc(sizeof(res_node));
				node->init(loginID, branch_list[coi1-1], tmpdate, hr, cos);
				rsl.add(node);

				printf("\n               Brach           Date    Hour     No of Customers\n");
				printf("%20s%15s%8d%20d\n", branch_list[coi1-1], tmpdate, hr, cos);

				printf("\nReservation successful!\n");
			}
			else if (T == 2) {
				printf("\n                  Brach           Date    Hour     No of Customers\n");
				For(i, 1, rsl.sz) {
					res_node* node = rsl.get(loginID, i);
					printf("%d. %20s%15s%8d%20d\n",i, node->branch, node->date, node->hour, node->cos);
				}
				printf("\nChoose a reservation to cancel (0: keep all reservations): ");
				int coi;
				scanf("%d", &coi);
				if (coi == 0) continue;
				else {
					if (coi < 0 || coi > rsl.sz) {
						printf("Invalid choice. Please try again.\n");
						continue;
					}
					rsl.del(coi);
					printf("\nReservation deleted!\n");
				}
			}
			else if (T == 3) {
				login = 0;
			}
			else {
			printf("Invalid choice. Please try again.\n");
			}
		}
	}

	system("pause");
	return 0;
}