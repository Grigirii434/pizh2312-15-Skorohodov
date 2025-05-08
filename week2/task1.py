from abc import ABC, abstractmethod
from datetime import datetime

class Likeable(ABC):
    @abstractmethod
    def like(self):
        pass

class Comment:
    def __init__(self, author: str, text: str):
        self.author = author
        self.text = text
        self.timestamp = datetime.now()

    def __str__(self):
        return f"{self.author} ({self.timestamp.strftime('%Y-%m-%d %H:%M')}): {self.text}"

class Post(Likeable):
    def __init__(self, author: str, text: str):
        self.__author = author                        
        self.__timestamp = datetime.now()
        self.__likes = 0
        self.__text = text
        self.__comments = []
        self.__profanity_count = 0

    def get_author(self):
        return self.__author

    def get_likes(self):
        return self.__likes

    def get_text(self):
        return self.__text

    def get_comments(self):
        return self.__comments

    def like(self):
        self.__likes += 1

    def add_comment(self, comment: Comment):
        self.__comments.append(comment)

    def __str__(self):
        comment_str = "\n".join(str(c) for c in self.__comments)
        return (f"Author: {self.__author}\n"
                f"Time: {self.__timestamp.strftime('%Y-%m-%d %H:%M')}\n"
                f"Likes: {self.__likes}\n"
                f"Text: {self.__text}\n"
                f"Comments:\n{comment_str if comment_str else 'No comments'}")

# Пример
post = Post(author="Григорий", text="Волчьи цитаты из статусов ВК")

# Ставим лайки
post.like()
post.like()

# Добавляем комментарии
comment1 = Comment(author="Влад", text="Кайф жи есть братишка")
comment2 = Comment(author="Леха", text="Поддерживаю")

post.add_comment(comment1)
post.add_comment(comment2)

# Выводим публикацию в консоль
print("=== Текстовая публикация ===")
print(post)