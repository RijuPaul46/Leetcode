# Write your MySQL query statement below
select s1.id,
COALESCE(s2.student,s1.student) as student
 from 
Seat as s1 left join Seat as s2 
ON (s1.id%2=1 AND s1.id=s2.id-1) OR (s1.id%2=0 AND s1.id-1=s2.id)
ORDER BY s1.id