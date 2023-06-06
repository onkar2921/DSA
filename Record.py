class Record:
    def __init__(self):
        self._name=None
        self._number=None

    def getName(self):
        return self._name
    
    def getNumber(self):
        return self._number
    
    def setName(self,name):
        self._name=name

    def setNumber(self,number):
        self._number=number

    def __str__(self):
        # record="Name :"+self.name+" "+"Number :"+self.number
        record = "Name: "+str(self.getName())+"\t"+"\tNumber: "+str(self.getNumber())
        return record
    
    
