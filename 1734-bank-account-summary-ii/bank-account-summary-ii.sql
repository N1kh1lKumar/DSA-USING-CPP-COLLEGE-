# Write your MySQL query statement below
select name , SUM(amount) as balance 
    from Users 
    join Transactions  using(account) 
    GROUP BY account
    having balance > 10000;