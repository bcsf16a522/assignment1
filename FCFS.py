process_array = []
waiting_time = 0
n = int(input('Enter total processes: '))
for j in range(n):
    process_array.append([])
    process_array[j].append(input('Enter name of process: '))
    process_array[j].append(int(input('Enter arrival time of process: ')))
    waiting_time = waiting_time + process_array[j][1]
    process_array[j].append(int(input('Enter brust time of process: ')))
    print ('')

process_array.sort(key = lambda process_array:process_array[1])

print ('ProcessName\tArrivalTime\tBurstTime')
for j in range(n):
    print (process_array[j][0],'\t\t',process_array[j][1],'\t\t',process_array[j][2])
    
print ('Average waiting time: ',(waiting_time/n))

currentTime = process_array[0][1]
turnarround_time=0
for x in range(n):
	currentTime = currentTime + process_array[x][2]	
	turnarround_time = turnarround_time + currentTime-process_array[x][1]
	print('Turnarount time for ',x,'process is :',(currentTime-process_array[x][1]))

	print('Average Turnaround time : ', turnarround_time /n)
