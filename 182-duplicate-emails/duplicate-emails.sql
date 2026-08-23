# Write your MySQL query statement below
select ifnull(email, null) AS Email from Person 
   group by email having count(email)>1;