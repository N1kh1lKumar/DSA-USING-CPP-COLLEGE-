# Write your MySQL query statement below
select u.name , ifnull(SUM(distance),0) AS travelled_distance 
    from Users u left join Rides r
    on u.id = r.user_id 
    group by r.user_id ORDER bY travelled_distance DESC, u.name ASC;