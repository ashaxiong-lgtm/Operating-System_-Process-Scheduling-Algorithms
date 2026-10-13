#include &lt;stdio.h&gt;
#include &lt;limits.h&gt;
#include &lt;stdbool.h&gt;

struct Process {
int pid;
int arrival_time;
int burst_time;
int priority;

int remaining_time;
int completion_time;
int turnaround_time;
int waiting_time;
int response_time;

bool started;
int count; // using it for aging
};

int main() {
int n;
int aging;

printf(&quot;Enter number of processes: &quot;);
scanf(&quot;%d&quot;, &amp;n);

printf(&quot;Enter aging threshold: &quot;);
scanf(&quot;%d&quot;, &amp;aging);

struct Process p[n];

for (int i = 0; i &lt; n; i++) {
p[i].pid = i + 1;

printf(&quot;Enter arrival time, burst time, and priority for P%d: &quot;, i + 1);
scanf(&quot;%d %d %d&quot;,
&amp;p[i].arrival_time,
&amp;p[i].burst_time,
&amp;p[i].priority);

p[i].remaining_time = p[i].burst_time;
p[i].started = false;
p[i].count = 0; // initial counting will start from 0
}

int current_time = 0;
int completed = 0;

float total_waiting_time = 0;

float total_turnaround_time = 0;
float total_response_time = 0;

while (completed &lt; n) {
int selected = -1;
int highest_priority = INT_MAX;

for (int i = 0; i &lt; n; i++) {
if (p[i].arrival_time &lt;= current_time &amp;&amp; p[i].remaining_time &gt; 0) {

if (p[i].priority &lt; highest_priority) {
highest_priority = p[i].priority;
selected = i;
}

else if (p[i].priority == highest_priority) {
if (p[i].arrival_time &lt; p[selected].arrival_time) {
selected = i;
}
}
}
}
//Aging code
for (int i = 0; i &lt; n; i++)
{
if (p[i].arrival_time &lt;= current_time &amp;&amp; p[i].remaining_time &gt; 0 &amp;&amp; i != selected)//
priotize the arival time
{
p[i].count++; // counting that how long the process is waiting
if (p[i].count % aging == 0 &amp;&amp; p[i].priority &gt; 1) // if count==aging threshold then and
priority cant be less then 1

{
p[i].priority--; // improving the priority
printf(&quot;Time %d: [AGING] P%d priority improved to %d\n&quot;, current_time, p[i].pid,
p[i].priority);
}
}
}

if (selected == -1) {
current_time++;
} else {
if (p[selected].started == false) {
p[selected].response_time = current_time - p[selected].arrival_time;
p[selected].started = true;
}

p[selected].remaining_time--;
current_time++;

if (p[selected].remaining_time == 0) {
p[selected].completion_time = current_time;

p[selected].turnaround_time = p[selected].completion_time -
p[selected].arrival_time;

p[selected].waiting_time = p[selected].turnaround_time - p[selected].burst_time;

total_waiting_time += p[selected].waiting_time;
total_turnaround_time += p[selected].turnaround_time;
total_response_time += p[selected].response_time;

completed++;
}
}
}

printf(&quot;\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n&quot;);

for (int i = 0; i &lt; n; i++) {
printf(&quot;P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n&quot;,
p[i].pid,
p[i].arrival_time,
p[i].burst_time,
p[i].priority, // Note: This prints their final, aged priority
p[i].completion_time,
p[i].turnaround_time,
p[i].waiting_time,
p[i].response_time);
}

printf(&quot;\nAverage Waiting Time = %.2f&quot;, total_waiting_time / n);
printf(&quot;\nAverage Turnaround Time = %.2f&quot;, total_turnaround_time / n);
printf(&quot;\nAverage Response Time = %.2f\n&quot;, total_response_time / n);

return 0;
}