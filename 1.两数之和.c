typedef struct hash_node {
   int id;            /* we'll use this field as the key */
   int index;
   UT_hash_handle hh; /* makes this structure hashable */
} hash_node;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *two_nums = (int *)malloc(sizeof(int)*2);  
    hash_node *hash_table = NULL, *hash_item1 = NULL, *hash_item2 = NULL;
    for (int i = 0; i < numsSize; i++) {
        // 查找哈希表中是否存在满足和为target的另一个值,若存在直接返回
        int other_id = target - *(nums+i);
        HASH_FIND_INT(hash_table, &other_id, hash_item1);
        if (hash_item1) {
            two_nums[0] = hash_item1->index;
            two_nums[1] = i;
            *returnSize = 2;
            return two_nums;
        }
        // 将本次遍历的值放入哈希表,value为数组下标,key为对应数值
        hash_item2 = (hash_node *)malloc(sizeof(hash_node));
        hash_item2->id = *(nums+i);
        hash_item2->index = i;
        HASH_ADD_INT(hash_table, id, hash_item2);
    }
    return two_nums;
}
