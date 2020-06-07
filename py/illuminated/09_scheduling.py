'''
In this programming problem and the next you'll code up the greedy algorithms from lecture for minimizing the weighted sum of completion times...

This file describes a set of jobs with positive and integral weights and lengths. It has the format

[number_of_jobs]

[job_1_weight] [job_1_length]

[job_2_weight] [job_2_length]

...

For example, the third line of the file is "74 59", indicating that the second job has weight 74 and length 59.

You should NOT assume that edge weights or lengths are distinct.

Your task in this problem is to run the greedy algorithm that schedules jobs in decreasing order of the difference (weight - length). Recall from
lecture that this algorithm is not always optimal. 

IMPORTANT: if two jobs have equal difference (weight - length), you should schedule the job with higher weight first. Beware: if you break ties 
in a different way, you are likely to get the wrong answer. You should report the sum of weighted completion times of the 
resulting schedule --- a positive integer --- in the box below.

ADVICE: If you get the wrong answer, try out some small test cases to debug your algorithm (and post your test cases to the discussion forum).

'''

import os

data_dir = os.getcwd() + '\\data\\illuminated\\scheduling\\'

submission_file_path = data_dir + 'jobs.txt'
test_file_path = data_dir + 'problem13.4test.txt'

class Job():

    def __init__(self, weight : int, length : int):
        self.weight = weight
        self.length = length
        self.complete = 0

    # diff scheduling
    def diff(self):
        return self.weight - self.length
    
    # ratio scheduling
    def ratio(self):
        return self.weight / self.length

def read_jobs_data(file_path):
    ''' read jobs

    this function simply reads a jobs definition
    file and returns a list of job objects per
    the specification.
    '''

    with open(file_path, 'r') as f:

        lines = f.read().splitlines()
        num_jobs = int(lines[0])
        
        # allocate storage
        jobs = [None] * num_jobs
        index = 0
        for line in lines[1:]:
            w, l = line.split(' ')
            jobs[index] = Job(int(w), int(l))
            index += 1

    return jobs

'''
schedule jobs by lowest diff first (weight as tie-breaker)
'''
def diff_order(j):
    return (-j.diff(), -j.weight)

'''
schedule jobs by lowest job w/l ratio first (no tie-breaker).
'''
def ratio_order(j):
    return -j.ratio()

def schedule_jobs(jobs, schedule):
    
    ordered_jobs = sorted(jobs, key=schedule)

    complete, weighted_complete = 0, 0

    for job in ordered_jobs:
        complete += job.length
        weighted_complete += complete * job.weight

    return weighted_complete

jobs = read_jobs_data(submission_file_path)

diff_wc = schedule_jobs(jobs, diff_order)
ratio_wc = schedule_jobs(jobs, ratio_order)

print([diff_wc, ratio_wc])