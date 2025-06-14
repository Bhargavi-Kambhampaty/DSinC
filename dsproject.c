#include <stdio.h>
#include <stdlib.h>

struct Compartment {
    int compartment_id;
    struct Compartment* next;
};

struct Train {
    struct Compartment* head;
};


struct Train* create_train() {
    struct Train* train = (struct Train*)malloc(sizeof(struct Train));
    train->head = NULL;
    return train;
}


void add_compartment(struct Train* train, int compartment_id) {
    struct Compartment* new_compartment = (struct Compartment*)malloc(sizeof(struct Compartment));
    new_compartment->compartment_id = compartment_id;
    new_compartment->next = NULL;

    if (train->head == NULL) {
        train->head = new_compartment;
    } else {
        struct Compartment* current = train->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_compartment;
    }
    printf("Compartment %d added.\n", compartment_id);
}


void remove_compartment(struct Train* train, int compartment_id) {
    if (train->head == NULL) {
        printf("Train is empty. No compartments to remove.\n");
        return;
    }

    struct Compartment* current = train->head;
    struct Compartment* previous = NULL;

    while (current != NULL && current->compartment_id != compartment_id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Compartment %d not found.\n", compartment_id);
        return;
    }

    if (previous == NULL) {
        train->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Compartment %d removed.\n", compartment_id);
}


void display_train(struct Train* train) {
    if (train->head == NULL) {
        printf("Train is empty.\n");
        return;
    }

    struct Compartment* current = train->head;
    printf("Train compartments: ");
    while (current != NULL) {
        printf("%d -> ", current->compartment_id);
        current = current->next;
    }
    printf("NULL\n");
}


void free_train(struct Train* train) {
    struct Compartment* current = train->head;
    struct Compartment* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(train);
}

int main() {
    struct Train* train = create_train();
    int choice, compartment_id;

    while (1) {
        printf("\nTrain Compartment Management\n");
        printf("1. Add Compartment\n");
        printf("2. Remove Compartment\n");
        printf("3. Display Train\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Compartment ID to add: ");
                scanf("%d", &compartment_id);
                add_compartment(train, compartment_id);
                break;
            case 2:
                printf("Enter Compartment ID to remove: ");
                scanf("%d", &compartment_id);
                remove_compartment(train, compartment_id);
                break;
            case 3:
                display_train(train);
                break;
            case 4:
                free_train(train);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
