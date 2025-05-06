class Post:

    def __init__(self, author, title, content):
        self.author = author  # Никнейм автора
        self.title = title  # Заголовок поста
        self.content = content  # Содержимое поста
        self.likes = 0  # Количество лайков
        self.comments = []  # Список комментариев
        self.timestamp = self.get_current_time()  # Время публикации

    def get_current_time(self):
        from datetime import datetime
        return datetime.now().strftime('%Y-%m-%d %H:%M:%S')

    def like(self):
        self.likes += 1  # Увеличиваем количество лайков

    def add_comment(self, comment):
        self.comments.append(comment)  # Добавляем комментарий

    def display(self):
        # Выводим информацию о посте
        print(f'Author: {self.author}\nTitle: {self.title}\nContent: {self.content}\nLikes: {self.likes}\nComments: {self.comments}\nPublished at: {self.timestamp}')

print("Вариант 15")

# Пример 1
post = Post('Grigirii434', 'Первый пост', 'Текст поста.')
post.like()  # Добавляем лайк
post.add_comment('Отличный пост!')  # Добавляем комментарий
post.display()  # Отображаем пост

# Пример 2
post = Post('Grigirii434', 'Второй пост', 'Текст второго поста.')
post.like()
post.add_comment('Супер!')
post.display()