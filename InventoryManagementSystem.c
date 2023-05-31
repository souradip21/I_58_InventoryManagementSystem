//Inventory Management System: Create a program that manages inventory, including tracking product sales, managing stock, and generating reports.
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    Product new_product;
    printf("Enter product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    products[num_products++] = new_product;
    printf("Product added successfully.\n");
}

void display_products() {
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

void sell_product() {
    int product_id, quantity;
    printf("Enter product ID: ");
    scanf("%d", &product_id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == product_id) {
            if (products[i].quantity >= quantity) {
                products[i].quantity -= quantity;
                printf("Sold %d units of %s.\n", quantity, products[i].name);
                return;
            } else {
                printf("Insufficient quantity.\n");
                return;
            }
        }
    }
    printf("Product not found.\n");
}

void generate_report() {
    float total_sales = 0;
    printf("ID\tName\tPrice\tQuantity\tSales\n");
    for (int i = 0; i < num_products; i++) {
        float sales = products[i].price * (float)(products[i].quantity);
        total_sales += sales;
        printf("%d\t%s\t%.2f\t%d\t%.2f\n", products[i].id, products[i].name, products[i].price, products[i].quantity, sales);
    }
    printf("Total sales: %.2f\n", total_sales);
}

int main() {
    int choice;
    do {
        printf("\nInventory Management System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Sell product\n");
        printf("4. Generate report\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                sell_product();
                break;
            case 4:
                generate_report();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}
