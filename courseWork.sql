use workers

create view worker_information as
    select schema_workers.workers_info.name as worker_name,
           schema_workers.workers_info.age as worker_age,
           schema_workers.workers_info.position as worker_position,
           schema_workers.worker_competence.hard_skills as worker_competence,
           schema_workers.workers_education.university as worker_education
FROM schema_workers.workers_info INNER JOIN schema_workers.worker_competence on workers_info.id = worker_competence.id
INNER JOIN schema_workers.workers_education on workers_info.id = workers_education.id;

create view worker_private as
    select schema_workers.workers_info.name as worker_name,
           schema_workers.worker_outlook.score as worker_score,
           schema_workers.worker_outlook.new_position as worker_new_position,
           schema_workers.workers_salary.salary_now as worker_salary,
           schema_workers.workers_salary.coeff as worker_coeff
           from schema_workers.workers_info inner join schema_workers.worker_outlook on workers_info.id = worker_outlook.id
inner join schema_workers.workers_salary on workers_info.id = workers_salary.id;
create procedure registration  @worker_name VARCHAR(100), @login varchar(100), @password varchar(100) as
    insert into schema_workers.workers_password values ((select workers_info.id
    from schema_workers.workers_info where name=@worker_name), @login, @password);
    select 1
    go

create procedure check_name @worker_name varchar(100) as
    select id from schema_workers.workers_info where name=@worker_name;
    go

create procedure check_password @worker_login varchar(100), @worker_password varchar(100) as
    select id from schema_workers.workers_password where login=@worker_login and password=@worker_password;
    go
create procedure get_competence @worker_login varchar(100) as
    select schema_workers.worker_competence.guide, schema_workers.worker_competence.hard_skills
    from schema_workers.worker_competence where worker_competence.id=(select id from schema_workers.workers_password
    where @worker_login=workers_password.login);
    go

create procedure get_education @worker_login varchar(100) as
    select schema_workers.workers_education.university from schema_workers.workers_education
    where workers_education.id=(select id from schema_workers.workers_password
    where @worker_login=workers_password.login);
    go

create procedure  get_salary @worker_login varchar(100) as
    select schema_workers.workers_salary.salary_now, schema_workers.workers_salary.coeff
    from schema_workers.workers_salary where workers_salary.id=(select id from schema_workers.workers_password
    where @worker_login=workers_password.login);
    go

create procedure get_score @worker_login varchar(100) as
    select schema_workers.worker_outlook.score, schema_workers.worker_outlook.new_position
    from schema_workers.worker_outlook where worker_outlook.id=(select id from schema_workers.workers_password
    where @worker_login=workers_password.login);
    go

create procedure registered @worker_name varchar(100) as
    select id from schema_workers.workers_password where schema_workers.workers_password.id=(select id from
            schema_workers.workers_info where @worker_name=schema_workers.workers_info.name)
    go


create procedure get_age @worker_name varchar(100) as
    select schema_workers.workers_info.age from schema_workers.workers_info
    where schema_workers.workers_info.name=@worker_name
    go

create procedure get_position @worker_name varchar(100) as
    select schema_workers.workers_info.position from schema_workers.workers_info
        where schema_workers.workers_info.name=@worker_name
    go

create procedure do_backup as
    backup database workers to disk='C:\backup SQL\1.sql'
    go
create procedure select_workers @age int, @skills varchar(100), @position varchar(100) as
    select schema_workers.workers_info.name from schema_workers.workers_info, schema_workers.worker_competence
    where schema_workers.workers_info.age=@age and schema_workers.worker_competence.hard_skills=@skills and schema_workers.workers_info.position=@position
    go
create procedure get_login @worker_name varchar(100) as
    select schema_workers.workers_password.login from schema_workers.workers_password where
                id=(select id from schema_workers.workers_info
                where schema_workers.workers_info.name=@worker_name)
    go

create procedure change_score @worker_name varchar(100), @new_score varchar(10) as
    update schema_workers.worker_outlook set score=@new_score where worker_outlook.id=(select id from schema_workers.workers_info
        where @worker_name=schema_workers.workers_info.name)
    go
create procedure change_guide @worker_name varchar(100), @new_guide varchar(100) as
        update schema_workers.worker_competence set guide=@new_guide where worker_competence.id=(select id from schema_workers.workers_info
        where @worker_name=schema_workers.workers_info.name)
    go


