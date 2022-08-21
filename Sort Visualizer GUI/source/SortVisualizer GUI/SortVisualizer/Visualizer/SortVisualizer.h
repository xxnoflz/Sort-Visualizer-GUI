#pragma once
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtOpenGL/QOpenGLFunctions_3_3_Core>
#include <QElapsedTimer>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Utilities/ResourceManager.h"
#include "../Render/quadRenderer.h"
#include "../Objects/CollumnArrayObject.h"

namespace sort {
	class SortVisualizer : public QOpenGLWidget, public QOpenGLFunctions_3_3_Core {
		Q_OBJECT
	public:
		struct TimeHandler {
			float currentTime;
			float lastTime;
			float deltaTime;
		};
		SortVisualizer(QWidget* parent = nullptr);

		void SetSpeed(uint32_t speed);
		void SetCollumnObject(CollumnArrayObject* object);

		void Render(uint32_t first_iter, uint32_t second_iter);
		void Render();

		void RenderCompletedSort();
		void RenderSort();
	protected:
		void initializeGL() override;
		void paintGL() override;
		void resizeGL(int width, int height) override;
	private:
		QElapsedTimer* timer;
		uint32_t speed;
		bool completion;

		uint32_t first_iter;
		uint32_t second_iter;

		quadRenderer* qRender;
		CollumnArrayObject* collumnObject;
	};
}