-- create database my_test_db;
create table aircraft
(
    name VARCHAR(100),
    id int not null primary key,
    passengers_count int not null
)



create table airline
(
    name VARCHAR(100),
    id int not null primary key,
)

create table route
(
    id int not null primary key,
    from_city VARCHAR(100),
    to_city varchar(100),
    distance int not null,
)


create table flight
(
    id int not null primary key,
    name VARCHAR(100),
    id_airline int not null,
    id_route int not null,
    distance int not null,
    foreign key (id_airline) references airline(id),
    foreign key (id_route) references route(id),
)

create table flight_route
(
    id_flight int not null,
    id_route int not null,
    time time,
    foreign key (id_flight) references flight(id),
    foreign key (id_route) references aircraft(id),
    primary key(id_flight, id_route, time)
)
alter table flight_route
    drop column time

alter table flight_route
	add time time
alter table flight_route
	add constraint flight_route_pk
		primary key nonclustered (time)


insert into airline values ('Pobeda', 1)
insert into route values (1,'Moscow', 'Kazan', 800)
-- insert into flight values (1, 'SD77', 1, 1)
insert into flight_route values (1,1, '17:30');
insert into aircraft values ('SDS4',2);
insert into aircraft values ('SDSd4',3, 400);

insert into airline values ('Aeroflot', 2)
insert into flight values (3, 'DD2', 1, 1)
insert into route values(2, 'Moscow', 'Kazan', 600)
insert into flight_route values(2, 2, '12:20')


-- insert into plane_flight(trip_number, plane_number) values (3, 4)
-- drop table plane_flight

-- alter table aircraft
--     drop constraint FK__aircraft__name__2D47B39A
-- INSERT  into aircraft(number, name) values (2, 'Aeroflot')

-- alter table flight
--     drop constraint FK__flight__name__2E3BD7D3
-- insert into flight(trip_number, passengers_count, time_arrival, name) values (1, 5, '14:30', 'Moscow')

-- insert into airline(name) values ('Superjet')
-- insert into route(name, distance) values ('Kazan-Moscow', 800)

-- ALTER table aircraft
-- Add name_company VARCHAR(100) REFERENCES airline(name)
-- ALTER table flight
-- Add name_rout VARCHAR(100) REFERENCES route(name)
-- create table plane_flight(
--     trip_number int not null,
--     plane_number int not null,
--     FOREIGN KEY(trip_number) references flight(trip_number),
--     foreign key (plane_number) references aircraft(number)
-- )

-- select * from dbo.airline

-- select * from dbo.flight
-- alter table aircraft
--     ADD name varchar(100),
--     FOREIGN KEY(name) REFERENCES airline(name);
-- select * from dbo.aircraft

-- insert into airline(name) values ('Pobeda')
-- insert into airline(name) values ('Tashkent')

-- insert into plane_flight(trip_number, plane_number) values (25, 74)
-- select * from dbo.route
-- insert into aircraft(number, name) values (5,'Pobeda')
--
--
-- ALTER table flight
--     Add name_rout VARCHAR(100),
--     FOREIGN KEY(name_rout)REFERENCES route(name)
--
-- insert into flight(trip_number, passengers_count, time_arrival, name, name_rout)
-- values (11, 6, '11:10', 'Kazan', 'Kazan-Moscow')
--
-- alter table flight
--     drop column name

-- select *from dbo.plane_flight
-- insert into   flight(trip_number, passengers_count, time_arrival, name_rout) values (4,40,'12:00', 'Kazan-Moscow')
-- insert into plane_flight(trip_number, plane_number) values (1,2)
-- select *from dbo.plane_flight
--     foreign key (plane_number) references aircraft(number)
-- insert into plane_flight(trip_number, plane_number) values (2,3)
-- insert into flight(trip_number, passengers_count, time_arrival, name_rout)
--  values(5, 10,'15:00' ,'Kazan - Samara')

insert into route values (3, 'Moscow', 'New-York', 700)

select distance from route where distance>600
SELECT *
FROM route
where distance BETWEEN 650 AND 790;
SELECT *
FROM route
WHERE distance IN (600,650)
SELECT *
FROM route
WHERE distance LIKE '%0';
SELECT *
FROM route
WHERE id IS NOT NULL;

select id from route where id>1
SELECT *
FROM aircraft
where passengers_count BETWEEN 100 AND 200;
SELECT *
FROM aircraft
WHERE passengers_count IN (100,200)
SELECT *
FROM aircraft
WHERE name LIKE '%4';
SELECT *
FROM aircraft
WHERE id IS NOT NULL;

select id from airline where id>1
SELECT *
FROM airline
where id BETWEEN 1 AND 2;
SELECT *
FROM airline
WHERE id IN (1,2)
SELECT *
FROM airline
WHERE name LIKE '%a';
SELECT *
FROM airline
WHERE id IS NOT NULL;

select id from flight where id>1
SELECT *
FROM flight
where id BETWEEN 1 AND 2;
SELECT *
FROM flight
WHERE id IN (1,2)
SELECT *
FROM flight
WHERE name LIKE '%7';
SELECT *
FROM flight
WHERE id IS NOT NULL;

select id_route from flight_route where id_route>1
SELECT *
FROM flight_route
where id_route BETWEEN 1 AND 2;
SELECT *
FROM flight_route
WHERE id_route IN (1,2)
SELECT *
FROM flight_route
WHERE id_route LIKE '%1';
SELECT *
FROM flight_route
WHERE id_route IS NOT NULL;

--
-- create table crew(
--     name_company varchar(100)  FOREIGN KEY references
--         airline(name),
--     employer_name varchar(100) not null,
--     experience_years int not null,
--     age int not null)
-- insert into crew(name_company, employer_name, experience_years, age)
-- values ('Pobeda', 'Masha', '5', '31')
-- insert into crew(name_company, employer_name, experience_years, age)
-- values ('Pobeda', 'Sasha', '10', '40')
-- insert into crew(name_company, employer_name, experience_years, age)
-- values ('Superjet', 'Taya', '14', '25')
-- insert into crew(name_company, employer_name, experience_years, age)
-- values ('Tashkent', 'Misha', 15, 45)
-- alter table flight  add airport varchar(100);
-- update flight set flight.airport='Sheremetevo' where name_rout='Kazan-Moscow';
-- update flight set flight.airport='Vnukovo' where name_rout='Kazan - Samara';

insert into flight_route values (3, 3, '14:30')
select avg(passengers_count), from_city, to_city, route.id from aircraft, flight_route, flight, route
where  flight.id_route = route.id and aircraft.id =flight_route.id_route and flight.id = flight_route.id_flight
group by route.id
select count(flight.id), route.from_city, route.to_city from flight, route group by  route.from_city, route.to_city
select count(id_airline), airline.name from flight, airline group by airline.name
-- select * from crew group by name_company, employer_name, experience_years, age HAVING AVG(experience_years) >=5 AND AVG(age) > 30;





