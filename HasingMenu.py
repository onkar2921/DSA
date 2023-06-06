from LinearProbing import HashTable
from Record import Record
from DoubleHashing import DoubleHash

obj1=HashTable()
obj2=DoubleHash()
while(True):
    ch=int(input("enter your choice:"))

    if(ch==1):
        record=Record()
        record.setName(input("enter the name"))
        record.setNumber(int(input("enter the number")))
        obj1.insertInHashTable(record)
        # obj2.insert(record)
    if(ch==2):
        obj1.display()

    if(ch==3):
        seacrhRC=Record()
        seacrhRC.setName(input("enter searching record name: "))
        seacrhRC.setNumber(int(input("enter search number: ")))
        obj1.searchRecord(seacrhRC)
    if(ch==4):
        seacrhRC=Record()
        seacrhRC.setName(input("enter searching record name: "))
        seacrhRC.setNumber(int(input("enter search number: ")))
        obj2.search(seacrhRC)
    if (ch==5):
        record=Record()
        record.setName(input("enter the name"))
        record.setNumber(int(input("enter the number")))
        obj2.insert(record)
 
    if(ch==6):
        obj2.display()