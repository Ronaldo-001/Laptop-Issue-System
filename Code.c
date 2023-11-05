#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct laptop {
    char brand[30];
    char model[30];
    int id;
    struct laptop *next;
};

struct student {
    char name[30];
    char email[20];
    char laptop[30];
    char a[30];
    int id;
    int malpractice_mark;  
    struct student *next;
};

struct laptop *start_laptops  = NULL;
struct student *start = NULL;

struct laptop *initialize_laptops(struct laptop *);
struct student *laptop_issue(struct student *);
struct student *laptop_return(struct student *);
void display_students(struct student *);
struct laptop *delete_laptop(int);
struct laptop *add_laptop(char[], char[], int);
struct student *edit_student_details(struct student *);
struct student *add_or_modify_malpractice_mark(struct student *);

void display(struct student *);
void greetings();
void main_menu();

int main() {
    start_laptops = initialize_laptops(start_laptops);
    greetings();
    main_menu();
    return 0;
}

void greetings() {

    printf("\n\n");
    printf("\t\t\t     **************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *       WELCOME TO LAPTOP ISSUER      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     **************\n");
    printf("\n\n");
    printf("\t\t\t     **************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *          LAPTOP MANAGEMENT          *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *       Potheri,Tamil Nadu, India    *\n");
    printf("\t\t\t     *   Email: laptopmanager@gmail.com    *\n");
    printf("\t\t\t     *   Contact: 8800991010, 8800992020   *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     **************\n");
  
}

void main_menu() {
    int choice;
    do {
        printf("\n\n");
        printf("\n\t\t\t*****************\n");
        printf("\n\t\t\t\t      MAIN MENU: ");
        printf("\n\t\t\t\t     1. ISSUE A LAPTOP ");
        printf("\n\t\t\t\t     2. RETURN A LAPTOP ");
        printf("\n\t\t\t\t     3. DISPLAY STUDENT DETAILS ");
        printf("\n\t\t\t\t     4. EDIT STUDENT DETAILS ");
        printf("\n\t\t\t\t     5. ADD/MODIFY MALPRACTICE MARKS ");
        printf("\n\t\t\t\t     6. EXIT\n ");
        printf("\n\t\t\t*****************\n");
        printf("\n\t\t\t\t      Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = laptop_issue(start);
                break;
            case 2:
                start = laptop_return(start);
                break;
            case 3:
                display_students(start);
                break;
            case 4:
                start = edit_student_details(start);
                break;
            case 5:
                start = add_or_modify_malpractice_mark(start);
                break;
            case 6:
                exit(0);
            default:
                printf("\n\t\t\t\t      ...Invalid Option!...\n");
               // printf("\n\t\t\t\t      Press any key to try again: ");
              //  getchar(); // Wait for user input
        }
    } while (choice != 6);
}



struct laptop *initialize_laptops(struct laptop *start) {
    struct laptop *ptr, *new_laptop1, *new_laptop2, *new_laptop3, *new_laptop4, *new_laptop5;

    new_laptop1 = (struct laptop *)malloc(sizeof(struct laptop));
    new_laptop1->next = NULL;
    start_laptops = new_laptop1;
    strcpy(new_laptop1->brand, "Dell");
    strcpy(new_laptop1->model, "XPS 13");
    new_laptop1->id = 101;
    ptr = new_laptop1;

    new_laptop2 = (struct laptop *)malloc(sizeof(struct laptop));
    new_laptop2->next = NULL;
    strcpy(new_laptop2->brand, "HP");
    strcpy(new_laptop2->model, "Spectre x360");
    new_laptop2->id = 102;
    ptr->next = new_laptop2;
    ptr = new_laptop2;

    new_laptop3 = (struct laptop *)malloc(sizeof(struct laptop));
    new_laptop3->next = NULL;
    strcpy(new_laptop3->brand, "Lenovo");
    strcpy(new_laptop3->model, "ThinkPad X1 Carbon");
    new_laptop3->id = 103;
    ptr->next = new_laptop3;
    ptr = new_laptop3;

    new_laptop4 = (struct laptop *)malloc(sizeof(struct laptop));
    new_laptop4->next = NULL;
    strcpy(new_laptop4->brand, "Apple");
    strcpy(new_laptop4->model, "MacBook Pro");
    new_laptop4->id = 104;
    ptr->next = new_laptop4;
    ptr = new_laptop4;

    new_laptop5 = (struct laptop *)malloc(sizeof(struct laptop));
    new_laptop5->next = NULL;
    strcpy(new_laptop5->brand, "Asus");
    strcpy(new_laptop5->model, "ZenBook Pro");
    new_laptop5->id = 105;
    ptr->next = new_laptop5;

    return start_laptops;
}

struct student *laptop_issue(struct student *start) {
    struct laptop *ptr;
    struct student *ptr2, *new_student;
    int i = 1, id, flag = 0;
    if (start_laptops == NULL) {
        printf("\n\t\t\t\t No laptops left in the inventory to issue!\n\t\t\t\t Sorry for the inconvenience!\n");
    } else {
        system("cls");
        ptr = start_laptops;
        printf("\n\t****** Laptops Available: *******\n");
        while (ptr != NULL) {
            printf("\n\t_________________\n");
            printf("\n\t Laptop %d", i);
            printf("\n\t Brand: %s", ptr->brand);
            printf("\n\t Model: %s", ptr->model);
            printf("\n\t Laptop ID: %d", ptr->id);
            printf("\n\t_________________\n");
            ptr = ptr->next;
            i++;
        }
        printf("\n\n\t Enter the Laptop ID: ");
        scanf("%d", &id);
        ptr = start_laptops;
        while (ptr != NULL) {
            if (ptr->id == id) {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 1) {
            ptr = start_laptops;
            while (ptr->id != id) {
                ptr = ptr->next;
            }
            new_student = (struct student *)malloc(sizeof(struct student));
            printf("\n\t Enter Student Details:\n ");
            printf("\n\t Enter your Name: ");
            scanf("%s", new_student->name);
            printf("\n\t Enter your Email: ");
            scanf("%s", new_student->email);
            strcpy(new_student->laptop, ptr->brand);
            strcpy(new_student->a, ptr->model);
            new_student->id = ptr->id;
            new_student->next = NULL;
            printf("\n\t Issue of Laptop ID %d done successfully!\n", new_student->id);
            printf("\n\n\t*****************\n");
            if (start == NULL) {
                start = new_student;
            } else {
                ptr2 = start;
                while (ptr2->next != NULL) {
                    ptr2 = ptr2->next;
                }
                ptr2->next = new_student;
            }
            start_laptops = delete_laptop(new_student->id);


        } else {
            printf("\n\t\t      ...Invalid Option!...\n");

        }
    }
    return start;
}

struct student *laptop_return(struct student *start) {
    struct student *ptr, *preptr;
    char laptopBrand[30], laptopModel[30];
    int flag = 0, id, identity, c = 0, d = 1;
    printf("\n\n\t****** Laptops Return: *******\n");
    printf("\n\n\t Enter your Laptop ID: ");
    scanf("%d", &identity);
    ptr = start;
    while (ptr != NULL) {
        if (ptr->id == identity) {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 1) {
        ptr = start;
        while (ptr != NULL) {
            c++;
            ptr = ptr->next;
        }
        ptr = start;
        while (ptr->id != identity) {
            d++;
            ptr = ptr->next;
        }
        ptr = start;
        if (d == 1) {
            printf("\n\t_________________\n");
            printf("\n\t Student Name: %s", start->name);
            printf("\n\t Student Email: %s", start->email);
            printf("\n\t Brand of Laptop Issued: %s", start->laptop);
            printf("\n\t_________________\n");
            printf("\n\n\t Return of Laptop ID %d done successfully!\n", identity);
            printf("\n\n\t*****************\n");
            strcpy(laptopBrand, start->laptop);
            strcpy(laptopModel, start->a);
            id = start->id;
            start = start->next;
            free(ptr);
            add_laptop(laptopBrand, laptopModel, id);
        } else {
            ptr = start;
            while (ptr->id != identity) {
                preptr = ptr;
                ptr = ptr->next;
            }
            printf("\n\t_________________\n");
            printf("\n\t Student Name: %s", ptr->name);
            printf("\n\t Student Email: %s", ptr->email);
            printf("\n\t Brand of Laptop Issued: %s", ptr->laptop);
            printf("\n\t Laptop ID: %d", ptr->id);
            printf("\n\t_________________\n");
            strcpy(laptopBrand, ptr->laptop);
            strcpy(laptopModel, ptr->a);
            id = ptr->id;
            preptr->next = ptr->next;
            free(ptr);
            add_laptop(laptopBrand, laptopModel, id);
        }
        printf("\n\t Thank you!\n\t Do visit again! ");
        printf("\n\n\t Press any key to go to the main menu: ");

    } else {
        printf("\n\tSorry the laptop doesn't exist! Please recheck the entered ID");
        printf("\n\t\t\t\t      Press any key to try again: ");

    }
    return start;
}
void display_students(struct student *start) {
    if (start == NULL) {
        printf("\nNo students found.\n");
    } else {
        struct student *ptr = start;
        while (ptr != NULL) {
            printf("\n\t***** Details of Students: ******\n");
            printf("\n\t_________________\n");
            printf("\n\t\t Student Name: %s", ptr->name);
            printf("\n\t\t Student Email: %s", ptr->email);
            printf("\n\t\t Laptop Issued: %s %s", ptr->laptop, ptr->a);
            printf("\n\t\t Laptop ID: %d", ptr->id);
            printf("\n\t_________________\n");
            printf("\n\n\t*****************\n");
            ptr = ptr->next;
        }
    }

}


void display(struct student *start) {
    if (start == NULL) {
        printf("\nNo students found.\n");
    } else {
        struct student *ptr = start;
        while (ptr != NULL) {
            printf("\n\t***** Details of Students: ******\n");
            printf("\n\t_________________\n");
            printf("\n\t\t Student Name: %s", ptr->name);
            printf("\n\t\t Student Email: %s", ptr->email);
            printf("\n\t\t Laptop Issued: %s %s", ptr->laptop, ptr->a);
            printf("\n\t\t Laptop ID: %d", ptr->id);
            printf("\n\t_________________\n");
            printf("\n\n\t*****************\n");
            ptr = ptr->next;
        }
    }

}

struct laptop *delete_laptop(int id) {
    struct laptop *ptr, *preptr;
    int c = 0;
    ptr = start_laptops;
    while (ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    if (c == 1) {
        ptr = start_laptops;
        start_laptops = NULL;
        free(ptr);
    } else if (start_laptops->id == id) {
        ptr = start_laptops;
        start_laptops = start_laptops->next;
        free(ptr);
    } else {
        ptr = start_laptops;
        while (ptr->id != id) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    return start_laptops;
}

struct laptop *add_laptop(char laptopBrand[30], char laptopModel[30], int id) {
    struct laptop *ptr, *new_laptop;
    new_laptop = (struct laptop *)malloc(sizeof(struct laptop));
    strcpy(new_laptop->brand, laptopBrand);
    strcpy(new_laptop->model, laptopModel);
    new_laptop->id = id;
    new_laptop->next = NULL;
    if (start_laptops == NULL) {
        start_laptops = new_laptop;
    } else {
        ptr = start_laptops;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_laptop;
    }
    return start_laptops;
}
struct student *edit_student_details(struct student *start) {
    int id, found = 0;
    char new_name[30];
    char new_email[20];

    if (start == NULL) {
        printf("\nNo students found to edit details.\n");
        return start;
    }

    printf("\n\nEnter the ID of the Laptop  which the Student Issued: ");
    scanf("%d", &id);

    struct student *ptr = start;
    while (ptr != NULL) {
        if (ptr->id == id) {
            found = 1;
            printf("\nEditing details for student with ID %d\n", id);
            printf("Enter new name: ");
            scanf("%s", new_name);
            printf("Enter new email: ");
            scanf("%s", new_email);
            strcpy(ptr->name, new_name);
            strcpy(ptr->email, new_email);
            printf("\nDetails for student with ID %d have been updated.\n", id);
            break;
        }
        ptr = ptr->next;
    }

    if (found == 0) {
        printf("\nStudent with ID %d not found.\n");
    }


    return start;
}

struct student *add_or_modify_malpractice_mark(struct student *start) {
    int id, mark;
    int found = 0;

    if (start == NULL) {
        printf("\nNo students found to add or modify malpractice marks.\n");
        return start;
    }

    printf("\n\nEnter the ID of the student for whom you want to add or modify malpractice marks: ");
    scanf("%d", &id);

    struct student *ptr = start;
    while (ptr != NULL) {
        if (ptr->id == id) {
            found = 1;
            printf("\nStudent ID: %d", id);
            printf("\nStudent Name: %s", ptr->name);
            printf("\nCurrent Malpractice Mark: %d", ptr->malpractice_mark);
            printf("\nEnter the new malpractice mark: ");
            scanf("%d", &mark);
            ptr->malpractice_mark = mark;
            printf("\nMalpractice mark for student with ID %d has been updated.\n", id);
            break;
        }
        ptr = ptr->next;
    }

    if (found == 0) {
        printf("\nStudent with ID %d not found.\n");
    }


    return start;
}
