class Solution:
    WEEK_DAYS = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        dt = date(year, month, day)
        return self.WEEK_DAYS[dt.weekday()]
