#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char description[100];
    float amount;
    char category[50];
} Transaction;

typedef struct
{
    Transaction *transactions;
    int size;
    int capacity;
} FinanceTracker;

FinanceTracker *createFinanceTracker(int capacity)
{
    FinanceTracker *ft = (FinanceTracker *)malloc(sizeof(FinanceTracker));
    if (!ft)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    ft->transactions = (Transaction *)malloc(sizeof(Transaction) * capacity);
    if (!ft->transactions)
    {
        printf("Memory allocation for transactions failed\n");
        free(ft);
        return NULL;
    }
    ft->size = 0;
    ft->capacity = capacity;
    return ft;
}

void addTransaction(FinanceTracker *ft, char *description, float amount, char *category)
{
    if (ft->size >= ft->capacity)
    {
        printf("Finance tracker is full. Cannot add more transactions.\n");
        return;
    }
    Transaction t;
    snprintf(t.description, sizeof(t.description), "%s", description);
    t.amount = amount;
    snprintf(t.category, sizeof(t.category), "%s", category);
    ft->transactions[ft->size++] = t;
}

void displayTransactionsByCategory(FinanceTracker *ft, char *category)
{
    printf("Transactions for category: %s\n", category);
    for (int i = 0; i < ft->size; i++)
    {
        if (strcmp(ft->transactions[i].category, category) == 0)
        {
            printf("%s: $%.2f\n", ft->transactions[i].description, ft->transactions[i].amount);
        }
    }
}

void displayMonthlySummary(FinanceTracker *ft)
{
    float totalIncome = 0.0, totalExpenses = 0.0;
    for (int i = 0; i < ft->size; i++)
    {
        if (ft->transactions[i].amount > 0)
        {
            totalIncome += ft->transactions[i].amount;
        }
        else
        {
            totalExpenses += ft->transactions[i].amount;
        }
    }
    printf("Monthly Summary:\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net: $%.2f\n", totalIncome + totalExpenses);
}

void saveTransactionsToFile(FinanceTracker *ft, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Failed to open file for writing.\n");
        return;
    }
    for (int i = 0; i < ft->size; i++)
    {
        fprintf(file, "%s,%.2f,%s\n", ft->transactions[i].description, ft->transactions[i].amount, ft->transactions[i].category);
    }
    fclose(file);
}

void loadTransactionsFromFile(FinanceTracker *ft, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open file for reading.\n");
        return;
    }
    char description[100], category[50];
    float amount;
    while (fscanf(file, "%99[^,],%f,%49[^\n]\n", description, &amount, category) == 3)
    {
        addTransaction(ft, description, amount, category);
    }
    fclose(file);
}

int main()
{
    int capacity = 10; // Initial capacity
    FinanceTracker *ft = createFinanceTracker(capacity);

    int running = 1;
    while (running)
    {
        printf("\n1. Add Transaction\n2. Display Transactions by Category\n3. Display Monthly Summary\n4. Save Transactions to File\n5. Load Transactions from File\n6. Exit\nSelect an option: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice)
        {
        case 1:
        {
            char description[100], category[50];
            float amount;
            printf("Enter transaction description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0; // Remove newline character
            printf("Enter amount: ");
            scanf("%f", &amount);
            getchar(); // Consume the newline character
            printf("Enter category: ");
            fgets(category, sizeof(category), stdin);
            category[strcspn(category, "\n")] = 0; // Remove newline character
            addTransaction(ft, description, amount, category);
            break;
        }
        case 2:
        {
            char category[50];
            printf("Enter category to display: ");
            fgets(category, sizeof(category), stdin);
            category[strcspn(category, "\n")] = 0; // Remove newline character
            displayTransactionsByCategory(ft, category);
            break;
        }
        case 3:
            displayMonthlySummary(ft);
            break;
        case 4:
        {
            char filename[100];
            printf("Enter filename to save transactions: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Remove newline character
            saveTransactionsToFile(ft, filename);
            break;
        }
        case 5:
        {
            char filename[100];
            printf("Enter filename to load transactions from: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Remove newline character
            loadTransactionsFromFile(ft, filename);
            break;
        }
        case 6:
            running = 0;
            break;
        default:
            printf("Invalid option.\n");
        }
    }

    // Free allocated memory
    free(ft->transactions);
    free(ft);

    return 0;
}