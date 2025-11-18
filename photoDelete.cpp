#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Photo
{
    int resolution;
    int date;
    vector<string> tags;
    Photo *next;
};

Photo* initPhoto(int r, int d, vector<string> ts)
{
    Photo *photo = new Photo;
    photo->resolution = r;
    photo->date = d;
    for(string t: ts)
    {
        photo->tags.push_back(t);
    }
    photo->next = nullptr;
    return photo;
}

void prependPhoto(Photo* head, Photo* newPhoto)
{
    Photo *temp = head;
    head = newPhoto;
    newPhoto->next = temp;
}

    Photo *filter(Photo *head, int reqResolution, int reqDate, string tag)
{
    Photo *curr = head;
    Photo *next;

    bool toRemove;
    while (curr)
    {
        for(string &t: curr -> tags)
        {
            if(curr->resolution < reqResolution || curr->date > reqDate || t == tag)
            {
                if(curr == head)
                {
                    head = curr->next;
                }
                toRemove = true;
            }
        }
        next = curr->next;
        if (toRemove)
        {
            delete (curr);
        }
        curr = next;
        }
    return head;
}

void printList(Photo *head){
    Photo*curr = head;
    while(curr)
    {
        cout << "Resolution: " << curr->resolution << " Date: " << curr->date << " Tags: ";
        for(string t: curr->tags)
        {
            cout << t << " ";
        }
        cout << endl;
        curr = curr->next;
    }
}

int main()
{
    Photo *p1 = initPhoto(800, 200, {"happy", "life"});
    Photo *p2 = initPhoto(200, 50, {"happy", "sad"});
    Photo *p3 = initPhoto(1000, 200, {"life"});

    prependPhoto(p1,p2);
    prependPhoto(p2,p3);

    printList(p3);

    Photo *newHead = filter(p3, 720, 365, "happy");
    cout << endl;
    printList(newHead);
}
