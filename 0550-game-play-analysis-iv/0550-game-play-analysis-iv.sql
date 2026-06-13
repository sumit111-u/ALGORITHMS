SELECT ROUND(
    COUNT(a.player_id) / COUNT(f.player_id)
, 2) AS fraction
FROM (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) f
LEFT JOIN Activity a
ON f.player_id = a.player_id
AND DATEDIFF(a.event_date, f.first_login) = 1