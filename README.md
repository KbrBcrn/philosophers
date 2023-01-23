# Philosophers Project

This project is about concurrent programming(opposed to sequential programming). For the mandatory part, we have to tackle the dining philosopher's problem with threads and mutexes and for the bonus part same problem with smaphores and processes.

 ## How to use
 
+ make - to compile the obligatory part
+ make bonus - to compile the bonus part

  The program take the following arguments:

* number_of_philosophers: The number of philosophers and also the number of forks.
* time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal, they die.
* time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
* time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
* number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the program stops. Otherwise,the program stops when a philosopher dies.

  The output seems like this;
```

    [timestamp_in_ms] [X] has taken a fork
    [timestamp_in_ms] [X] is eating
    [timestamp_in_ms] [X] is sleeping
    [timestamp_in_ms] [X] is thinking
    [timestamp_in_ms] [X] died
 
```
*** Attention to data races, deadlocks.

Each philosopher is a thread. I didnot create an extra thread to check whether philophers are still alive, main process checks that.

Each fork is protected by a mutex.

A mutex is created to print messages to avoid a scramble view.

A mutex is to check the deaths.

Keep in mind to handle zero philo situation and regarding to eveluation instruction handle the situation of more than 200 philosophers. (I couldnot achieve the first evaluation on that account.)

 
### Some useful resources

  * Tutorial about [threads](https://randu.org/tutorials/threads/).
  * [CodeVault](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
  * An article about [Threads, Mutexes and Concurrent Programming in C](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/) which helped me so much to figure the concept out.
  * [Kill](https://www.youtube.com/watch?v=5We_HtLlAbs&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=16&ab_channel=CodeVault)
System Call in C.
  * Very good explanations about [smaphores](https://zafersatilmiscom.wordpress.com/2020/01/14/semafor-ve-mutex-kavramlari/) (In Turkish)
