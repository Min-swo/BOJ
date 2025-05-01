
SELECT * FROM 
(SELECT CASE 
        WHEN (SKILL_CODE & C.FE) <> 0 AND (SKILL_CODE & P.PYTHON) <> 0 THEN 'A'
        WHEN (SKILL_CODE & CS.CS) <> 0 THEN 'B'
        WHEN (SKILL_CODE & C.FE) <> 0 THEN 'C'
        ELSE 'D'
        END AS GRADE, ID, EMAIL 
            FROM DEVELOPERS D
                JOIN (SELECT SUM(`CODE`) AS FE FROM SKILLCODES
                        WHERE CATEGORY = 'Front End'
                            GROUP BY CATEGORY) C
                JOIN (SELECT `CODE` AS PYTHON FROM SKILLCODES
                        WHERE NAME = 'Python') P
                JOIN (SELECT `CODE` AS CS FROM SKILLCODES
                        WHERE NAME = 'C#') CS) T
    WHERE T.GRADE <> 'D'
        ORDER BY GRADE, ID
                    

    