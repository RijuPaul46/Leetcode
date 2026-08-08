# Write your MySQL query statement below
SELECT distinct(l1.num) as ConsecutiveNums
from Logs as l1 join (
    select l2.id as s,l2.num as n from  Logs as l2 join Logs as l3 
    ON l3.id=l2.id+1
    where l3.num = l2.num
 ) as l4
ON l4.s=l1.id+1 
where l1.num=l4.n