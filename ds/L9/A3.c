struct WashingMachine {
    int machineID;
    int rentedTime;
    int inUse;
};

struct Node {
    struct WashingMachine machine;
    struct Node* next;
    struct Node* prev;
};
