//
// Created by manuelpagoada on 2/18/23.
//
/***************************************************************************************
*    Title: <title of program/source code>
*    Author: <author(s) names>
*    Date: <date>
*    Code version: <code version>
*    Availability: <where it's located>
*
***************************************************************************************/

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
ItemType SortedType::GetItem(ItemType item, ItemType[] arr)
{
    int midPoint;
    int first = 0;
    int last = length - 1;

    bool moreToSearch = first <= last;

    while (moreToSearch)
    {
        //set up midPoint
       midPoint=(first+last)/2;

        //check if x is present
       if(arr[midPoint]==item){return midPoint;}

        //check if x greater, ignore left half
        if(arr[midPoint]<item){
            first=midPoint+1;
        } else {
            //check if x is smaller, ignore right half
            last=midPoint-1;
        }



    }
    return midPoint;
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

