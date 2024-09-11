#ifndef SCENENODE_HPP
#define SCENENODE_HPP

#include <memory>
#include <vector>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, public sf::NonCopyable
{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;
		typedef std::pair<SceneNode*, SceneNode*> Pair;

	
	public:
		explicit			SceneNode();

		void				attachChild(Ptr child);
		// Ptr				detachChild(const SceneNode& node);

		void				update(sf::Time dt);

	
	private:
		virtual void		updateCurrent(sf::Time dt);
		void				updateChildren(sf::Time dt);

		virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void				drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
	

	private:
		std::vector<Ptr>	mChildren;
		SceneNode*			mParent;
};

#endif // SCENENODE_HPP