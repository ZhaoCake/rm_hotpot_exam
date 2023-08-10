import os
import random
import shutil


def split_dataset(root_dir, train_ratio, val_ratio, test_ratio):
    # 创建存储数据集的文件夹
    os.makedirs(os.path.join(root_dir, 'train', 'images'), exist_ok=True)
    os.makedirs(os.path.join(root_dir, 'train', 'labels'), exist_ok=True)
    os.makedirs(os.path.join(root_dir, 'val', 'images'), exist_ok=True)
    os.makedirs(os.path.join(root_dir, 'val', 'labels'), exist_ok=True)
    os.makedirs(os.path.join(root_dir, 'test', 'images'), exist_ok=True)
    os.makedirs(os.path.join(root_dir, 'test', 'labels'), exist_ok=True)

    # 获取所有图像和标签的文件名
    filenames = [
        filename.split('.')[0] for filename in os.listdir(root_dir)
        if filename.endswith('.jpg')
    ]

    # 打乱文件名列表
    random.shuffle(filenames)

    # 计算训练集、验证集和测试集的样本数量
    total_samples = len(filenames)
    train_samples = int(total_samples * train_ratio)
    val_samples = int(total_samples * val_ratio)

    # 将文件按比例分配到训练集、验证集和测试集
    train_filenames = filenames[:train_samples]
    val_filenames = filenames[train_samples:train_samples + val_samples]
    test_filenames = filenames[train_samples + val_samples:]

    # 将图像和标签文件分别复制到相应的目录中
    for filename in train_filenames:
        shutil.copy(os.path.join(root_dir, f'{filename}.jpg'),
                    os.path.join(root_dir, 'train', 'images'))
        shutil.copy(os.path.join(root_dir, f'{filename}.txt'),
                    os.path.join(root_dir, 'train', 'labels'))
    for filename in val_filenames:
        shutil.copy(os.path.join(root_dir, f'{filename}.jpg'),
                    os.path.join(root_dir, 'val', 'images'))
        shutil.copy(os.path.join(root_dir, f'{filename}.txt'),
                    os.path.join(root_dir, 'val', 'labels'))
    for filename in test_filenames:
        shutil.copy(os.path.join(root_dir, f'{filename}.jpg'),
                    os.path.join(root_dir, 'test', 'images'))
        shutil.copy(os.path.join(root_dir, f'{filename}.txt'),
                    os.path.join(root_dir, 'test', 'labels'))


def main(data_root):
    # 定义数据集根目录
    dataset_root = data_root

    # 定义训练集、验证集和测试集的比例
    train_ratio = 0.7  # 70%用于训练
    val_ratio = 0.15  # 15%用于验证
    test_ratio = 0.15  # 15%用于测试

    # 分割数据集
    split_dataset(dataset_root, train_ratio, val_ratio, test_ratio)
    print("Finished Splitting Dataset!")
    # 并没有删除原本在data_root中的文件，以避免搞砸了难以挽救。可以在数据集目录下使用rm *.jpg *.txt来删除


if __name__ == '__main__':
    data_root = input("Please input the dataset root: ")  # 可输入，以后碰到这种数据集都可以用
    main(data_root)
