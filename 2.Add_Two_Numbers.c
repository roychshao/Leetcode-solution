struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int val1 = 0, val2 = 0, val3 = 0, flag = 0, temp = 0;
    struct ListNode* current1 = l1;
    struct ListNode* current2 = l2;
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->val = -1;
    l3->next = NULL;
    while (current1 != NULL || current2 != NULL)
    {
        if (current1 != NULL)
            val1 = current1->val;
        else
            val1 = 0;
        if (current2 != NULL)
            val2 = current2->val;
        else
            val2 = 0;
        temp = val1 + val2;
        if ((temp+flag) >= 10)
        {
            if (flag)
            {
                //add(temp - 9,l3);
                struct ListNode* tmp;
                if (l3->val == -1)
                {
                    tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->val = temp - 9;
                    tmp->next = NULL;
                    l3 = tmp;
                }
                else
                {
                    struct ListNode* current = l3;
                    while (current->next != NULL)
                        current = current->next;
                    tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->val = temp - 9;
                    tmp->next = NULL;
                    current->next = tmp;
                }
            }
            else
            {
                //add(temp - 10,l3);
                struct ListNode* tmp;
                if (l3->val == -1)
                {
                    tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->val = temp - 10;
                    tmp->next = NULL;
                    l3 = tmp;
                }
                else
                {
                    struct ListNode* current = l3;
                    while (current->next != NULL)
                        current = current->next;
                    tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->val = temp - 10;
                    tmp->next = NULL;
                    current->next = tmp;
                }
            }
            flag = 1;
        }
        else
        {
            if (flag)
            {
                //add(temp + 1, l3);
                struct ListNode* tmp;
                if (l3->val == -1)
                {
                    tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->val = temp + 1;
                    tmp->next = NULL;
                    l3 = tmp;
                }
                else
                {
                    struct ListNode* current = l3;
                    while (current->next != NULL)
                        current = current->next;
                    tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->val = temp + 1;
                    tmp->next = NULL;
                    current->next = tmp;
                }
            }
            else
            {
                //add(temp, l3);
                struct ListNode* tmp;
                if (l3->val == -1)
                {
                    tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->val = temp;
                    tmp->next = NULL;
                    l3 = tmp;
                }
                else
                {
                    struct ListNode* current = l3;
                    while (current->next != NULL)
                        current = current->next;
                    tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
                    tmp->val = temp;
                    tmp->next = NULL;
                    current->next = tmp;
                }
            }
            flag = 0;
        }
        if (current1 != NULL)
            current1 = current1->next;
        if (current2 != NULL)
            current2 = current2->next;
    }
    if(flag)
    {
        struct ListNode* tmp;
        struct ListNode* current = l3;
        while (current->next != NULL)
            current = current->next;
        tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = 1;
        tmp->next = NULL;
        current->next = tmp;
    }
    return l3;
}

// test vim-fugitive
