-- 코드를 작성해주세요
# SELECT ID, EMAIL, FIRST_NAME, LAST_NAME FROM DEVELOPERS
#     WHERE SKILL_CODE & 1024 = 1024 or SKILL_CODE & 256 = 256
#         ORDER BY ID;
    
    
    
SELECT DISTINCT  ID, EMAIL, FIRST_NAME, LAST_NAME 
    FROM DEVELOPERS d JOIN SKILLCODES s
                ON (s.NAME = 'C#' or s.NAME = 'Python') 
                    and d.SKILL_CODE & s.CODE = s.CODE
        ORDER BY ID;