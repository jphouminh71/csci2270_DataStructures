#include "pq.cpp"

int main(int argc, char* argv[])
{

  PriorityQueue hospital(stoi(argv[1]));
  string choice = "";

  int totalWaitTime = 0;

  while(choice != "6")
  {
    cout << "======Main Menu======" << endl;
    cout << "1. Get Patient Information from File" << endl;
    cout << "2. Add Patient to Priority Queue" << endl;
    cout << "3. Show Next Patient" << endl;
    cout << "4. Admit Next Patient" << endl;
    cout << "5. Process Entire Queue" << endl;
    cout << "6. Quit" << endl;
    getline(cin,choice);
    switch(stoi(choice))
    {
    case 1:
    {
        if (hospital.isFull())
        {
          cout << "full" << endl;
        }
        else
        {
          ifstream infile(argv[2]);
          if (infile.fail())
          {
            cout << "File failed to open. " << endl;
          }
          if (infile.is_open())                        // read in existing patients in the queue
          {
            //cout << "File opened successfully!" << endl;
            string line;
            while(getline(infile,line))
            {
              string name;
              string severity;
              string treatmentTime;
              stringstream ss;
              ss << line;

              getline(ss,name,' ');
              getline(ss,severity,' ');
              getline(ss,treatmentTime,' ');
              if (!hospital.isFull())
              {
                //cout << "Adding: " << name << endl;
                hospital.enqueue(name,stoi(severity),stoi(treatmentTime));  // chekcing if the queue is full or not will be handled in the enqueue function
              }
              else
              {
                cout << "Priority Queue full. Send remaining patients to another hospital." <<	endl;
              }

            }
          }
          infile.close();
        }
      }
      break;
      case 2:   // adding patient to priority queue
      {
        if (hospital.isFull())
        {
          cout << "Priority Queue full. Send Patient to another hospital." << 	endl;
        }
        else{             // user will enter information to queue another patient
          string name;
          string severity;
          string treatmentTime;
          cout << "Enter Patient Name:" << endl;
          getline(cin,name);
          cout << "Enter Injury Severity:" << endl;
          getline(cin,severity);
          cout << "Enter Treatment Time:" << endl;
          getline(cin,treatmentTime);
          hospital.enqueue(name, stoi(severity), stoi(treatmentTime));
        }
      }
      break;
      case 3:     // peeks the next person in the queue
      {
        if (hospital.isEmpty())
        {
          cout << "Queue empty." << endl;
        }
        else
        {
          cout << "Patient Name: " << hospital.peekName() << endl;
          cout << "Injury Severity: " << hospital.peekInjurySeverity() << endl;
          cout << "Treatment Time: " << hospital.peekTreatmentTime() << endl;
        }
      }
      break;
      case 4: // dequeue and then repair downwards
      {
        if (hospital.isEmpty())
        {
          cout << "Queue empty." << endl;
        }
        else{
          totalWaitTime = totalWaitTime + hospital.peekTreatmentTime();
          cout << "Patient Name: " << hospital.peekName() << " - " << "Total Time Treating Patients: " << totalWaitTime << endl;
          hospital.dequeue();
        }
      }
      break;
      case 5:
      {
        if (hospital.isEmpty())
        {
          cout << "Queue empty." << endl;
        }
        else{
          while(!hospital.isEmpty())
          {
            totalWaitTime = totalWaitTime + hospital.peekTreatmentTime();
            cout << "Patient Name: " << hospital.peekName() << " - " << "Total Time Treating Patients: " << totalWaitTime << endl;
            hospital.dequeue();
          }
        }
      }
      break;
      case 6:
      {
        cout << "Goodbye!" << endl;
      }
      break;
    }
  }
  return 0;
}
