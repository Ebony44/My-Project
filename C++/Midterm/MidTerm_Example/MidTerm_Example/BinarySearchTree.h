#pragma once

#include <stack>
#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:

		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree& other) = delete;
		virtual ~BinarySearchTree() = default;
		const BinarySearchTree& operator=(const BinarySearchTree& rhs) = delete;

		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);


		//std::weak_ptr<TreeNode<T>> RecurParentElement(std::shared_ptr<TreeNode<T>> node) const;
		//std::shared_ptr<TreeNode<T>> RecurLeftElement(std::shared_ptr<TreeNode<T>> node) const;
		//std::shared_ptr<TreeNode<T>> RecurRightElement(std::shared_ptr<TreeNode<T>> node) const;


		//std::shared_ptr<TreeNode<T>> TraverseInOrderLeftEnd(std::shared_ptr<TreeNode<T>> node) const;
		//static void TraverseInOrderInput(std::shared_ptr<TreeNode<T>> node, std::vector<T>& v);


	private:
		//std::unique_ptr<TreeNode<T>> mRoot;
		std::shared_ptr<TreeNode<T>> mRoot;
		//TreeNode<T> mRoot;
	};

	template<typename T> BinarySearchTree<T>::BinarySearchTree()
		: mRoot(nullptr)
	{

	}


	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{


		// 1. mRoot condition, if it's empty.
		// or it's left and right.
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<TreeNode<T>>(std::move(data));
			//mRoot = std::make_unique<TreeNode<T>>(std::move(data));
			//mRoot->Data = std::move(data);
			return;
		}

		if (mRoot->Left == nullptr)
		{
			if (*data <= *(mRoot->Data))
			{
				mRoot->Left = std::make_shared<TreeNode<T>>(std::move(data));
				mRoot->Left->Parent = mRoot;
				return;
			}
		}
		if (mRoot->Right == nullptr)
		{
			if (*data > * (mRoot->Data))
			{
				mRoot->Right = std::make_shared<TreeNode<T>>(std::move(data));
				mRoot->Right->Parent = mRoot;
				return;
			}

		}

		// 2. now it's start

		// 
		std::shared_ptr<TreeNode<T>> tempNode = mRoot;
		bool bTempNodeSelected = false;
		bool bTempInserted = false;
		while (bTempNodeSelected == false || tempNode == nullptr)
		{
			// TODO
			// 1. both empty

			if (tempNode->Left != nullptr && tempNode->Right != nullptr)
			{
				if (*data <= *(tempNode->Data))
				{
					tempNode = tempNode->Left;

					continue;
				}
				else
				{
					tempNode = tempNode->Right;

					continue;
				}
			}
			/*
			else if (tempNode->Left != nullptr && *data == *(tempNode->Data))
			{
				// 4 if parameter data is same as root but left is already filled in.
				// this condition shoud be more prior...?

				tempNode = tempNode->Left;

				continue;

			}
			*/
			else if (tempNode->Left != nullptr && *data <= *(tempNode->Data))
			{
				// 2. left


				tempNode = tempNode->Left;

				continue;
			}
			else if (tempNode->Right != nullptr && *data > * (tempNode->Data))
			{
				// 3. right

				// think 2 1 3 5 7 7 7 7 6 6
				// every 7 will be right of (parent of) 7.. really right sided
				// after that, two 6s will be left of first 7.

				/*
				if (tempNode->Left == nullptr && *(tempNode->Right->Data) > *data)
				{
					bTempNodeSelected = true;
					continue;
				}
				*/
				tempNode = tempNode->Right;

				continue;
			}

			// 5, 6 if left or right is empty after all that conditions
			else if (tempNode->Left == nullptr)
			{
				bTempNodeSelected = true;
				continue;
			}
			else if (tempNode->Right == nullptr)
			{
				bTempNodeSelected = true;
				continue;
			}
			// above is make mTempRoot is RootNode in this process


		}

		// below is process of inserting

		if (tempNode->Left == nullptr)
		{
			if (*data <= *(tempNode->Data))
			{
				tempNode->Left = std::make_shared<TreeNode<T>>(std::move(data));
				tempNode->Left->Parent = tempNode;

				return;
			}
		}

		if (tempNode->Right == nullptr)
		{
			if (*data > * (tempNode->Data))
			{
				tempNode->Right = std::make_shared<TreeNode<T>>(std::move(data));
				tempNode->Right->Parent = tempNode;

				return;
			}

		}

		// bigger than root, smaller than right

		if (tempNode->Right != nullptr && tempNode->Left == nullptr && *(tempNode->Right->Data) > * data)
		{
			if (*data < *tempNode->Data)
			{
				return;
			}
			tempNode->Left = std::make_shared<TreeNode<T>>(std::move(data));
			tempNode->Left->Parent = tempNode;

			return;
		}




	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		//std::shared_ptr<TreeNode<T>> n = std::make_shared<TreeNode<T>>()
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> tempNode = mRoot;
		while (tempNode != nullptr)
		{

			if (data < *tempNode->Data)
			{
				if (tempNode->Left != nullptr)
				{
					//tempNode = RecurLeftElement(tempNode);
					tempNode = tempNode->Left;
				}
				else if (tempNode->Left == nullptr)
				{
					break;
				}

			}
			else if (data > * tempNode->Data)
			{
				if (tempNode->Right != nullptr)
				{
					//tempNode = RecurRightElement(tempNode);
					tempNode = tempNode->Right;
				}
				else if (tempNode->Right == nullptr)
				{
					break;
				}

			}
			if (data == *tempNode->Data)
			{
				return true;
			}
			if (tempNode->Left == nullptr && tempNode->Right == nullptr)
			{
				break;
			}
		}

		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{




		/*
		bool bFounded = Search(data);
		std::shared_ptr<TreeNode<T>> tempNode = mRoot;

		std::shared_ptr<TreeNode<T>> deletedNode = nullptr;

		// 1. search the node to delete
		// same as Search(const T& data)....
		// after search, deletedNode will filled in.

		while (tempNode != nullptr)
		{

			if (data < *tempNode->Data)
			{
				if (tempNode->Left != nullptr)
				{
					tempNode = RecurLeftElement(tempNode);
				}
				else if (tempNode->Left == nullptr)
				{
					break;
				}

			}
			else if (data > * tempNode->Data)
			{
				if (tempNode->Right != nullptr)
				{
					tempNode = RecurRightElement(tempNode);
				}
				else if (tempNode->Right == nullptr)
				{
					break;
				}

			}
			if (data == *tempNode->Data)
			{
				deletedNode = tempNode;
				break;
			}
			if (tempNode->Left == nullptr && tempNode->Right == nullptr)
			{
				break;
			}
		}

		if (deletedNode == nullptr)
		{
			return false;
		}

		// 2. deleting process
		// while condition is always true if deletedNode founded. must breeak inside

		tempNode = deletedNode;
		bool bLeftMoved = false;
		bool bLeftRightExsits = true;
		std::shared_ptr<TreeNode<T>> tempParentNode;

		// 0. root deleting

		if (*deletedNode->Data == *mRoot->Data)
		{
			tempNode = mRoot;
			// 0.0. only mRoot exsists.
			if (mRoot->Right == nullptr && mRoot->Left == nullptr)
			{
				mRoot = nullptr;
				deletedNode = nullptr;
				return true;
			}

			// 0.1. right is only left element

			if (tempNode->Left == nullptr && mRoot->Right != nullptr)
			{

				if (mRoot->Right->Left == nullptr && mRoot->Right->Right == nullptr)
				{

					tempNode = mRoot->Right;
					mRoot = tempNode;
					mRoot->Right = nullptr;
					deletedNode = nullptr;

					//mRoot = nullptr;
					return true;
				}
				mRoot = mRoot->Right;
				return true;
			}
			// left is only left element
			if (tempNode->Left != nullptr && tempNode->Right == nullptr)
			{
				if (mRoot->Left->Left == nullptr && mRoot->Left->Right == nullptr)
				{

					tempNode = mRoot->Left;
					mRoot = tempNode;
					mRoot->Left = nullptr;
					deletedNode = nullptr;

					//mRoot = nullptr;
					return true;
				}
				mRoot = mRoot->Left;
				return true;
			}




			// 0.2. left isn't empty
			tempNode = tempNode->Left;
			while (tempNode->Right != nullptr)
			{
				tempNode = tempNode->Right;
			}

			//  deleted node's parent to left, vice versa
			tempParentNode = tempNode->Parent.lock();
			tempParentNode->Right = tempNode->Left;

			if (tempNode->Left != nullptr)
			{
				tempNode->Left->Parent = tempParentNode;
			}

			// mRoot deleteing.
			// right condition
			if (mRoot->Right != nullptr)
			{
				tempNode->Right = mRoot->Right;
				mRoot->Right->Parent = tempNode;

			}
			// left condition
			if (mRoot->Left != tempNode)
			{
				tempNode->Left = mRoot->Left;
				mRoot->Left->Parent = tempNode;
			}

			mRoot = tempNode;
			tempNode->Parent.reset();
			deletedNode = nullptr;
			return true;

		}

		// delete process
		while (deletedNode != nullptr)
		{
			// left = same or smaller than parent
			// right = larger than parent
			// largest node in left subtree

			// 0. no left node

			//std::shared_ptr<TreeNode<T>> tempCheckLeftNode;
			if (tempNode->Left == nullptr && tempNode->Right != nullptr)
			{
				tempParentNode = tempNode->Parent.lock();
				tempNode->Parent = tempParentNode;

				tempNode = tempNode->Right;
				tempParentNode->Right = tempNode;

				deletedNode = nullptr;
				return true;
			}

			// 1. move to left and forget it.
			// -> if Left's Right is nullptr....
			// -> don't move this.
			if (tempNode->Left != nullptr && bLeftMoved == false)
			{
				if (tempNode->Left->Right == nullptr)
				{
					std::shared_ptr<TreeNode<T>> tempLeftNode = tempNode->Left;
					// left to deleted parent, deleted parent to left
					tempLeftNode->Parent = deletedNode->Parent.lock();
					tempParentNode = deletedNode->Parent.lock();
					if (tempParentNode->Left == tempNode)
					{
						tempParentNode->Left = tempLeftNode;
					}
					else if (tempParentNode->Right == tempNode)
					{
						tempParentNode->Right = tempLeftNode;
					}


					//left to deleted right, deleted right to left


					if (tempNode->Right != nullptr)
					{
						tempLeftNode->Right = deletedNode->Right;
						tempNode->Right->Parent = tempLeftNode;
					}


					return true;
				}
				tempNode = tempNode->Left;
				bLeftMoved = true;
				continue;
			}
			// 2. if no left subtree at deletedNode

			if (tempNode->Left != nullptr && bLeftMoved == false)
			{
				tempNode = tempNode->Right;
				tempNode->Parent = deletedNode->Parent.lock();
				tempNode->Left = deletedNode->Left;
				tempNode->Right = deletedNode->Right;
				deletedNode = tempNode;
				return true;
			}

			// 2.5 same and last

			if (*(deletedNode->Data) == *(tempNode->Data) && deletedNode->Left == nullptr && deletedNode->Right == nullptr)
			{

				tempNode = tempNode->Parent.lock();

				// if it was left, delete left or delete right.
				if (tempNode->Left != nullptr)
				{
					if (*deletedNode->Data == *tempNode->Left->Data)
					{
						tempNode->Left = nullptr;
					}
				}
				if (tempNode->Right != nullptr)
				{

					if (*deletedNode->Data == *tempNode->Right->Data)
					{
						tempNode->Right = nullptr;
					}
				}


				deletedNode = nullptr;
				return true;

			}
			// 3. for largest node in left subtree, always moved to right.
			if (tempNode->Right != nullptr)
			{
				tempNode = tempNode->Right;
			}
			else if (tempNode->Right == nullptr)
			{
				//tempNode = tempNode->Right;
				tempNode->Parent = deletedNode->Parent.lock();
				if (deletedNode->Left != nullptr)
				{
					if (*(deletedNode->Left->Data) == *(tempNode->Data))
					{

						tempNode->Left = nullptr;
					}
					else
					{
						tempNode->Left = deletedNode->Left;
					}
				}
				tempNode->Right = deletedNode->Right;

				// delete from deleteNode's Parent

				if (deletedNode->Parent.expired() == false)
				{

					tempParentNode = deletedNode->Parent.lock();
					tempParentNode->Right = tempNode;
				}



				deletedNode = nullptr;
				return true;

			}

		}

		*/
		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		std::stack<std::shared_ptr<TreeNode<T>>> s;

		std::shared_ptr<TreeNode<T>> tempNode = startNode;
		while (tempNode != nullptr || s.empty() == false)
		{
			// left end node

			while (tempNode != nullptr)
			{

				//s.push(*(tempNode->Data.get()));
				s.push(tempNode);
				tempNode = tempNode->Left;
			}
			// reach the end of left.
			tempNode = s.top();
			s.pop();

			v.push_back(*(tempNode->Data.get()));
			tempNode = tempNode->Right;

		}



		// firstly, reach the last of left node

		//TraverseInOrderInput(startNode, v);


		/*
		std::shared_ptr<TreeNode<T>> tempLastNode = startNode;
		while (tempLastNode->Right != nullptr)
		{
			tempLastNode = tempLastNode->Right;
		}
		std::shared_ptr<TreeNode<T>> tempNode = startNode;
		while (tempNode != nullptr)
		{
			tempNode = TraverseInOrderLeftEnd(tempNode);

		}
		*/




		return v;
	}




	/*
	template<typename T>
	std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::RecurParentElement(std::shared_ptr<TreeNode<T>> node) const
	{
		return node->Parent;
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::RecurLeftElement(std::shared_ptr<TreeNode<T>> node) const
	{
		return node->Left;
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::RecurRightElement(std::shared_ptr<TreeNode<T>> node) const
	{
		return node->Right;
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::TraverseInOrderLeftEnd(std::shared_ptr<TreeNode<T>> node) const
	{

		//std::shared_ptr<TreeNode<T>> tempLeftNode = node;
		std::shared_ptr<TreeNode<T>> tempNode = node;
		while (tempNode->Left != nullptr)
		{
			tempNode = tempNode->Left;
			//tempLeftNode = tempLeftNode->Left;

		}

		return tempNode;

	}


	template<typename T>
	void BinarySearchTree<T>::TraverseInOrderInput(std::shared_ptr<TreeNode<T>> node, std::vector<T>& v)
	{

		if (node == nullptr)
		{
			return;
		}

		TraverseInOrderInput(node->Left, v);

		v.push_back(*(node->Data.get()));

		TraverseInOrderInput(node->Right, v);

		return;



	}
	*/

}