SELECT S.hacker_id, H.name, SUM(S.score) AS total_score
FROM Hackers H JOIN (SELECT hacker_id, challenge_id, MAX(score) AS score
                    FROM Submissions
                    GROUP BY hacker_id, challenge_id) S ON S.hacker_id=H.hacker_id
GROUP BY S.hacker_id, H.name
HAVING total_score > 0
ORDER BY total_score DESC, S.hacker_id ASC;
