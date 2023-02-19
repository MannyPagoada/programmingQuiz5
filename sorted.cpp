//
// Created by manuelpagoada on 2/18/23.
//
#include "ItemType.h"
#include "sorted.h"

SortedType::SortedType()
{
    length = 0;
}

void SortedType::MakeEmpty()
{
    length = 0;
}


bool SortedType::IsFull() const
{
    return (length == MAX_ITEMS);
}

int SortedType::GetLength() const
{
    return length;
}
ItemType SortedType::GetItem(ItemType item, bool& found)
{
    int midPoint;
    int first = 0;
    int last = length - 1;

    bool moreToSearch = first <= last;
    found = false;
    while (moreToSearch && !found)
    {
        midPoint = ( first + last) / 2;
        switch (item.ComparedTo(info[midPoint]))
        {
            case LESS    : last = midPoint - 1;
                moreToSearch = first <= last;
                break;
            case GREATER : first = midPoint + 1;
                moreToSearch = first <= last;
                break;
            case EQUAL   : found = true;
                item = info[midPoint];
                break;
        }
    }
    return item;
}
void SortedType::DeleteItem(ItemType item, ItemType[] arr)
{
    //find position from getItem

    int index=sorted.GetItem();


    //remove by shifting
    for(int i= index; index<sizeof(arr);i++){
        arr[index]=arr[index+1];
    }

    //get rid of length
    length--;

}

void SortedType::PutItem(ItemType item, ItemType[] arr)
{
    arr[length]=item;
    length++;
}
void SortedType::ResetList()
// Post: currentPos has been initialized.
{
    currentPos = -1;
}
int SortedType::searchItem(ItemType item) const
{
    int low = 0;
    int high = length - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (list[mid] == item)
            return mid;
        else if (list[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

ItemType SortedType::GetNextItem()
// Post: item is current item.
//       Current position has been updated.
{
    currentPos++;
    return info[currentPos];
}

