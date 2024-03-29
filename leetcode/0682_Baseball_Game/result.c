/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-02-08 11:44:29
 *   Description   ：
 */
typedef struct __round_t {
    int points;
    struct __round_t *next;
} round_t;

round_t *remove_round(round_t *head) {
    round_t *new_head = NULL;
    if (head) {
        new_head = head->next;
        free(head);
        head = NULL;
    }
    return new_head;
}

round_t *add_round(round_t *head, int points) {
    round_t *node = malloc(sizeof(round_t));
    node->points = points;
    node->next = NULL;
    
    if (head) {
        node->next = head;
    }
    
    return node;
}

int sum_points(round_t *head) {
    int points = 0;
    while (head) {
        points += head->points;
        head = remove_round(head);
    }
    return points;
}

int calPoints(char** ops, int opsSize) {
    round_t *head = NULL;
    
    for (int i = 0; i < opsSize; ++i) {
        // Remove last round.
        if (strcmp(ops[i], "C") == 0) {
            head = remove_round(head);
            
        // Use double of last round's points.
        } else if (strcmp(ops[i], "D") == 0) {
            if (head) {
               head = add_round(head, head->points * 2);
            }
            
        // Use sum of last two rounds.
        } else if (strcmp(ops[i], "+") == 0) {
            int points = 0;
            if (head) {
                points += head->points;
            }
            if (head->next) {
                points += head->next->points;
            }
            head = add_round(head, points);
            
        // Add normal round.
        } else {
            head = add_round(head, atoi(ops[i]));
        }
    }
    
    return sum_points(head);
} 

int main(){
    return 0;
}
