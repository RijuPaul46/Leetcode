# Write your MySQL query statement below
with empDept as(
    select 
    e.name as Employee,
    e.salary as Salary,
    e.departmentId,
    d.name as Department_name,
    DENSE_RANK() over (partition by d.id order by e.salary DESC) as rank_num
    from Employee as e JOIN Department as d
    ON e.departmentId=d.id
)
select Department_name as Department, Employee , Salary from empDept
where rank_num<=3