import pyodbc


class Database:
    def __init__(self):
        self.__cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER=localhost;DATABASE=workers;Port=1433;autocommit=True')
        self.cursor = self.__cnxn.cursor()

    def checkFIO(self, FIO:str):
        self.cursor.execute(f"exec check_name '{FIO}'")
        row = self.cursor.fetchone()
        return row

    def check_registr(self,  FIO:str):
        self.cursor.execute(f"exec registered '{FIO}'")
        row = self.cursor.fetchone()
        return row

    def add_log(self, FIO:str, login:str, passw:str):
        self.cursor.execute(f"exec registration '{FIO}', '{login}', '{passw}'")
        self.__cnxn.commit()

    def check_passw(self, login: str, passw: str):
        self.cursor.execute(f"exec check_password '{login}', '{passw}'")
        row = self.cursor.fetchone()
        return row

    def get_age(self, name: str):
        self.cursor.execute(f"exec get_age '{name}'")
        row = self.cursor.fetchone()
        if row:
            return row[0]
        else:
            return ''

    def get_position(self, name: str):
        self.cursor.execute(f"exec get_position '{name}'")
        row = self.cursor.fetchone()
        if row:
            return row[0]
        else:
            return ''

    def get_education(self, login: str):
        self.cursor.execute(f"exec get_education '{login}'")
        row = self.cursor.fetchone()
        if row:
            return row[0]
        else:
            return ''

    def get_salary(self, login: str):
        self.cursor.execute(f"exec get_salary '{login}'")
        row = self.cursor.fetchone()
        if row:
            return row
        else:
            return ''

    def get_score(self, login: str):
        self.cursor.execute(f"exec get_score '{login}'")
        row = self.cursor.fetchone()
        if row:
            return row[0]
        else:
            return ''

    def get_score(self, login: str):
        self.cursor.execute(f"exec get_score '{login}'")
        row = self.cursor.fetchone()
        if row:
            return row
        else:
            return ''

    def get_competence(self, login: str):
        self.cursor.execute(f"exec get_competence '{login}'")
        row = self.cursor.fetchone()
        if row:
            return row
        else:
            return ''
