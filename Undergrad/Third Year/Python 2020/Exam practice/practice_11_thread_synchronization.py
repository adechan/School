# Curs 11
# THREAD AND SYNCHRONIZATION

# _thread

import _thread, time
def Print(sleepPeriod, name, count):
    for i in range(0, count):
        print(name + "=> " + str(i))
        time.sleep(sleepPeriod)

# create a new thread that will execute the Print function with the given parameters
# we don't know which one gets executed first
def ex1():
    _thread.start_new_thread(Print, (1, "Thread #1", 3))
    _thread.start_new_thread(Print, (2, "Thread #2", 2))
    _thread.start_new_thread(Print, (3, "Thread #3", 1))
    time.sleep(10)  # to make sure that the main thread doesnt end its execution until the other 3 threads get executed as well

# ex1()

# LOCK:
# when it receives an ACQUIRE, it makes sure that ONLY 1 thread can execute
# it ends with RELEASE, to allow other threads to execute

# LOCK: WITH (it has defined ACQUIARE and RELEASE)


def ex2():
    def MyPrint(sleepPeriod, name, count):
        global lock
        for i in range(-count, count):
            # it won't stop the program because we are not in the main thread
            print(name + " => " + str(10/i))  # will throw an exception
            time.sleep(sleepPeriod)

    _thread.start_new_thread(MyPrint, (1, "Thread #1", 3))
    for i in range(0, 10):
        print("Main thread " + str(i))
        time.sleep(1)

# ex2()

# Thread

import threading, time

def ex3():
    def WaitSomeSeconds(seconds, x, y):
        time.sleep(seconds)
        print(x + y)

    t = threading.Thread(target= WaitSomeSeconds, args = (5, 10, 20))  # TUPLE
    t.start()  # start the thread
    print("Wait for the thread to complete...")
    t.join()  # waits till the thread terminates

# ex3()

# SYNCHRONIZATION

# 1. LOCK: nu spune ordinea pentru threads, ci doar spune ca
# un singur thread va putea sa execute
# o data ce un fire a facut ACQUIRE, niciun alt fir nu mai poate face
# (nici macar el insusi) => poate duce la DEADLOCK

# 2. RLOCK:
# acelasi fir poate face mai multe ACQUIRES daca l-a obtinut deja pe primul
# daca faci ACQUIRES de 10 ori, trebuie sa faci RELEASE de 10 ori


# 3. CONDITION OBJECT: permite cuiva sa fie notificat cand o anumita
# conditie s-a indeplinit

# 4. SEMAPHORES
# mai multe fire de executie au acces la o resursa


# s = threading.Semaphore(4)  # cate fire de executie au acces la o resursa la un moment dat (4)
# def WorkerThread(id):
#     global s
#     with s:
#         print("Thread - #" + str(id) + " enter")
#         time.sleep(1)
#         print("Thread - #" + str(id) + " exit")
#
# t = []
# for i in range(0, 10):
#     t += [threading.Thread(target = WorkerThread, args=(i, ))]
#
# for _th in t:
#     _th.start()
# for _th in t:
#     _th.join()
print("=================")

# 5. TIMER: iti permite sa rulezi cod dupa un anumit timp
# 6. EVENT: iti permite sa sincronizezi executia intre 2+ threads

e1 = threading.Event()
e2 = threading.Event()
e1.set()   # semnalizam primul eveniment

def AddNumber(start, event1, event2, lista):
    for i in range(start, 10, 2):
        event1.wait()
        event1.clear()
        lista += [i]
        event2.set()

l = []
t1 = threading.Thread(target= AddNumber, args= (1, e1, e2, l))
t2 = threading.Thread(target= AddNumber, args= (2, e2, e1, l))

t1.start()
t2.start()
t1.join()
t2.join()
print(l)

# 7. BARRIER: mai multe fire pornesc in acelasi timp o executie
# DEADLOCK (se poate ajunge la cazuri in care daca ai Barrier(3), se asteapta mereu
# 3 fire de executie, altfel nu continua)