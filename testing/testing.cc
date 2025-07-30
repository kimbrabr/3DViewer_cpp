#include <gtest/gtest.h>

#include <cmath>
#include <fstream>

#include "../controller/command.h"
#include "../controller/controller.h"
#include "../model/model.h"
#include "../model/obj_loader.h"

namespace s21 {
class ModelTest : public ::testing::Test {
 protected:
  Model model;
  Controller controller{&model};
};

TEST_F(ModelTest, LoadInvalidFile) {
  controller.LoadModel("nonexistent.obj");
  EXPECT_TRUE(controller.GetModel()->GetVertices().empty());
  EXPECT_TRUE(controller.GetModel()->GetFaces().empty());
}

TEST_F(ModelTest, LoadFromFile) {
  controller.LoadModel("obj_files/cube.obj");

  const auto& vertices = controller.GetModel()->GetVertices();
  const auto& faces = controller.GetModel()->GetFaces();

  // std::cout << "Vertices size: " << vertices.size() << std::endl;
  // std::cout << "Faces size: " << faces.size() << std::endl;

  EXPECT_EQ(vertices.size(), 8);
  EXPECT_EQ(faces.size(), 6);

  EXPECT_EQ(faces[0].vertex_indices.size(), 4);

  EXPECT_FLOAT_EQ(vertices[0].x, -1.0f);
  EXPECT_FLOAT_EQ(vertices[0].y, -1.0f);
  EXPECT_FLOAT_EQ(vertices[0].z, -1.0f);
  EXPECT_FLOAT_EQ(vertices[7].x, 1.0f);
  EXPECT_FLOAT_EQ(vertices[7].y, 1.0f);
  EXPECT_FLOAT_EQ(vertices[7].z, 1.0f);
}

TEST_F(ModelTest, Move) {
  controller.LoadModel("obj_files/cube.obj");
  controller.MoveModel(1.0f, 2.0f, 3.0f);

  const auto& vertices = controller.GetModel()->GetVertices();

  EXPECT_FLOAT_EQ(vertices[0].x, 0.0f);  // -1 + 1
  EXPECT_FLOAT_EQ(vertices[0].y, 1.0f);  // -1 + 2
  EXPECT_FLOAT_EQ(vertices[0].z, 2.0f);  // -1 + 3
}

TEST_F(ModelTest, Scale) {
  controller.LoadModel("obj_files/cube.obj");
  controller.ScaleModel(2.0f);

  const auto& vertices = controller.GetModel()->GetVertices();

  EXPECT_EQ(vertices[0].x, -2.0f);  // -1 * 2
  EXPECT_EQ(vertices[0].y, -2.0f);
  EXPECT_EQ(vertices[0].z, -2.0f);
}

TEST_F(ModelTest, Rotate) {
  controller.LoadModel("obj_files/cube.obj");
  controller.RotateModel(90.0f, 0.0f, 0.0f);

  const auto& vertices = controller.GetModel()->GetVertices();

  EXPECT_FLOAT_EQ(vertices[0].x, -1.0f);
  EXPECT_NEAR(vertices[0].y, 1.0f, 1e-5);
  EXPECT_NEAR(vertices[0].z, -1.0f, 1e-5);
}

TEST_F(ModelTest, MoveCommand) {
  controller.LoadModel("obj_files/cube.obj");
  std::unique_ptr<Command> cmd =
      std::make_unique<MoveCommand>(1.0f, 0.0f, 0.0f);
  cmd->Execute(*controller.GetModel());

  const auto& vertices = controller.GetModel()->GetVertices();
  EXPECT_FLOAT_EQ(vertices[0].x, 0.0f);  // -1 + 1
}

TEST_F(ModelTest, ScaleCommand) {
  controller.LoadModel("obj_files/cube.obj");
  std::unique_ptr<Command> cmd = std::make_unique<ScaleCommand>(2.0f);
  cmd->Execute(*controller.GetModel());

  const auto& vertices = controller.GetModel()->GetVertices();
  EXPECT_FLOAT_EQ(vertices[0].x, -2.0f);
}

TEST_F(ModelTest, RotateCommand) {
  controller.LoadModel("obj_files/cube.obj");
  std::unique_ptr<Command> cmd =
      std::make_unique<RotateCommand>(90.0f, 0.0f, 0.0f);
  cmd->Execute(*controller.GetModel());

  const auto& vertices = controller.GetModel()->GetVertices();
  EXPECT_NEAR(vertices[0].z, -1.0f, 1e-5);
}

TEST_F(ModelTest, LoadEmptyFile) {
  controller.LoadModel("obj_files/empty.obj");
  EXPECT_TRUE(controller.GetModel()->GetVertices().empty());
  EXPECT_TRUE(controller.GetModel()->GetFaces().empty());
}

TEST_F(ModelTest, PrintModelInfo) {
  controller.LoadModel("obj_files/skull.obj");
  // std::cout << "Count of vertices: "
  //  << controller.GetModel()->GetVertices().size() << std::endl;
  // std::cout << "Count of faces: " << controller.GetModel()->GetFaces().size()
  //  << std::endl;
}

}  // namespace s21

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
