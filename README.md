# CPU_Scheduling_Algorithms
This project contains codes of 7 basic CPU Scheduling Algorithms in C++ to run on your terminal or code editor.<br />
These Algorithms include:<br />
1.**FCFS**(**First Come First Serve**)<br />
2.**SJF**(**Shortest Job First**)<br />
3.**HRRN**(**Highest Response Ratio Next**)<br />
4.**SRTF**(**Shortest Remaining Time First**)<br />
5.**Premptive Priority Scheduling**<br />
6.**Non Premptive Priority Scheduling**<br />
7.**Round Robin** <br />
<br />
## Input Format for Programs
**1**.**FCFS**, **SJF**, **HRRN**, **SRTF** <br />
  **Example-**<br />
   3 <br />
  1 2 3 <br />
  2 3 4 <br />
  3 4 5<br />
   First Line contains one input i.e **No.of Process(N)**
   Now the next N lines contain the information about the processes
  i.e **(Process-id,Arrival-Time,Burst-Time)**. 
  **NOTE-** **Keep Process-Id of every process unique**<br /><br />
**2**. **Round-Robin** <br /> 
**Example-**<br />
3 2<br />
1 2 3<br />
2 3 4<br />
3 4 5 <br/>
First line contains two inputs i.e **No.of Process(N)** and **Time-Quantum(TQ)**
Now the next N lines contain the information about processes
i.e **(Process-id,Arrival-Time,Burst-Time)**.
**NOTE-** **Keep Process-Id of every process unique**
	**NOTE-** **The value of TQ must be greater than zero Integer Value**
<br /><br />
**3.** **Premptive-Priority and Non-Premptive Priority-Scheduling** <br/>
**Example**<br />
3<br />
1 2 3 2<br />
2 3 4 3<br />
3 4 5 5<br />
First Line contains one input i.e **No.of Process(N)**
   Now the next N lines contain the information about the processes
  i.e **(Process-id,Arrival-Time,Burst-Time,Process-Priority)**.
    **NOTE-** **Keep Process-Id of every process unique**
    **NOTE**- The algo works on the principle of Higher the value of Process Priority
    Higher would be the preference. To change its default behaviour, you can change the comparator function of the priority_queue ready in the Program.

