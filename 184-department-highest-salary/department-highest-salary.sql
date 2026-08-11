# Write your MySQL query statement below
 with new_table as(
    select d.name  as depart,
        e.name as name,
        salary ,
        RANK() over (partition by d.id order by e.salary DESC) as row_num
    from Employee as e join Department as d 
    on e.departmentId=d.id
 )
 select depart as Department ,
    name as Employee,
    salary as Salary 
    from new_table
    where row_num=1;
    