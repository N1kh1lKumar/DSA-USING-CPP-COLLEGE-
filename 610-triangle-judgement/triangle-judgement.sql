# Write your MySQL query statement below
select x, y, z , if(x+y > z AND y+z > x AND z+x > y, 'Yes' , 'No')  AS triangle 
    from Triangle;