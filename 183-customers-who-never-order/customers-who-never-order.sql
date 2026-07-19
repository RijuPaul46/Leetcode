# Write your MySQL query statement below
select name as Customers
from Customers 
where id not in(
    Select Customers.id from 
    Customers INNER JOIN Orders
    ON  Customers.id=Orders.customerId
);