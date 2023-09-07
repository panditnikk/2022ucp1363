#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRAINS 10
#define MAX_SEATS 50

typedef struct {
    int trainNumber;
    char trainName[50];
    int totalSeats;
    int availableSeats;
} Train;

Train trains[MAX_TRAINS];
int numTrains = 0;

void initializeTrains() {
    Train train1 = {1, "Express Train", 100, 100};
    Train train2 = {2, "Local Train", 150, 150};

    trains[0] = train1;
    trains[1] = train2;

    numTrains = 2;
}

void displayTrains() {
    printf("\nAvailable Trains:\n");
    for (int i = 0; i < numTrains; i++) {
        printf("%d. %s (%d seats)\n", trains[i].trainNumber, trains[i].trainName, trains[i].availableSeats);
    }
}

int bookTicket(int trainNumber, int numSeats) {
    for (int i = 0; i < numTrains; i++) {
        if (trains[i].trainNumber == trainNumber) {
            if (trains[i].availableSeats >= numSeats) {
                trains[i].availableSeats -= numSeats;
                return 1; // Ticket booked successfully
            } else {
                return 0; // Not enough seats available
            }
        }
    }
    return -1; // Train not found
}

int main() {
    initializeTrains();

    int choice;
    do {
        printf("\nRailway Reservation System\n");
        printf("1. Display available trains\n");
        printf("2. Book a ticket\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTrains();
                break;
            case 2: {
                int trainNumber, numSeats;
                printf("Enter train number: ");
                scanf("%d", &trainNumber);
                printf("Enter number of seats: ");
                scanf("%d", &numSeats);
                int result = bookTicket(trainNumber, numSeats);
                if (result == 1) {
                    printf("Ticket booked successfully!\n");
                } else if (result == 0) {
                    printf("Sorry, not enough seats available.\n");
                } else {
                    printf("Train not found.\n");
                }
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

